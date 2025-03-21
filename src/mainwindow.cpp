// mainwindow.cpp
#include <QMenuBar>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QRandomGenerator> // 新增（用于randomPage）
#include <QTextLayout>
#include <QApplication>
#include <QTextBlock>
#include <QPushButton>
#include <QVBoxLayout>
#include <algorithm>

#include "mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	m_hotkeyMainwindow(nullptr),
	settings(new Settings()),  // 先创建 settings
	settingsDialog(new SettingsDialog(settings)),
	tdm(new TextDocumentManager(settings)),
	view(new TextReaderView()),
	model(new TextDocumentModel()),
	trayIcon(new QSystemTrayIcon(this)),
	contextMenu(new QMenu(this)),
	restoreAction(new QAction("Restore", this)),
	exitAction(new QAction("Exit", this))
{  

	//setWindowFlags(Qt::WindowCloseButtonHint);
	setAttribute(Qt::WA_TranslucentBackground);

	initUI();

	initTrayIcon();

	initHotkey();
	// 设置窗口最小化时隐藏到托盘
	//setWindowState(Qt::WindowNoState);

	tdm->linkViewAndModel(view, model);

	//tdm->openFile();

	//todo:: set修改
	connect(settings, &Settings::settingsChanged, tdm, &TextDocumentManager::applySettings);

}

MainWindow::~MainWindow() {
	// 确保析构时释放资源
	if (view) {
		view->close();
		delete view;
		view = nullptr;  // 防止重复删除
	}

	if (tdm) {
		delete tdm;
		tdm = nullptr;  // 防止重复删除
	}

	if (model) {
		delete model;
		model = nullptr;  // 防止重复删除
	}
	

	if (trayIcon->isVisible()) {
		trayIcon->hide();
	}

	if (m_hotkeyMainwindow) {
		delete m_hotkeyMainwindow;
		m_hotkeyMainwindow = nullptr;
	}

	if (settings) {
		delete settings;
		settings = nullptr;
	}
	
}

void MainWindow::initHotkey() {
	m_hotkeyMainwindow = new QHotkey(QKeySequence("Ctrl+X"), true, this);
	if (!m_hotkeyMainwindow->isRegistered()) {
		QMessageBox::warning(nullptr, "Warning", "hot key registration failed!");
	}

	QObject::connect(m_hotkeyMainwindow, &QHotkey::activated, qApp, &QApplication::quit);
}

void MainWindow::closeEvent(QCloseEvent* event) {
	// 显示托盘图标并最小化窗口
	if (!trayIcon->isVisible())
	{
		trayIcon->show();
	}
	tdm->tableView()->hide();
	this->hide();
	event->ignore();  // 忽略关闭事件，防止程序退出
	// 让用户知道程序仍在运行
	//trayIcon->showMessage(QStringLiteral("程序仍在后台运行"), QStringLiteral("点击托盘图标可恢复窗口"), QSystemTrayIcon::Information, 3000);

}


void MainWindow::changeEvent(QEvent* event) {
	if (event->type() == QEvent::WindowStateChange) {
		if (isMinimized()) {
			// 窗口最小化时隐藏窗口，只显示托盘图标
			hide();
			if (!trayIcon->isVisible())
			{
				trayIcon->show();
			}
		}
	}
	QMainWindow::changeEvent(event);
}

void MainWindow::initTrayIcon() {
	trayIcon->setToolTip("My Application");
	trayIcon->setIcon(QIcon("E:\\code\\cProject\\protectEYE\\images\\thief.png")); // 设置托盘图标
	// 创建托盘菜单
	createTrayMenu();
}

void MainWindow::initUI() {

	// 创建一个按钮
	QPushButton* settingsButton = new QPushButton("Settings", this);
	settingsButton->setStyleSheet("QPushButton { padding: 5px; }");

	QPushButton* menuButton = new QPushButton("Menu", this);
	menuButton->setStyleSheet("QPushButton { padding: 5px; }");

	QPushButton* studyButton = new QPushButton("study", this);
	studyButton->setStyleSheet("QPushButton { padding: 5px; }");

	// 设置布局
	QVBoxLayout* layout = new QVBoxLayout();
	//layout->addWidget(textLabel);
	layout->addWidget(settingsButton);  // 将按钮加入布局
	layout->addWidget(menuButton);  // 将按钮加入布局
	layout->addWidget(studyButton);  // 将按钮加入布局

	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(layout);
	setCentralWidget(centralWidget);

	// 直接在 connect 中使用 lambda 调用 settingsDialog->exec()
	connect(settingsButton, &QPushButton::clicked, this, [this]() {
		settingsDialog->exec();
		});

	// 连接按钮的点击事件
	connect(studyButton, &QPushButton::clicked, this, &MainWindow::test);

	connect(menuButton, &QPushButton::clicked, this, &MainWindow::onChapterSelectClicked);
}


void MainWindow::test() {

	tdm->tableView()->show();
}

void MainWindow::createTrayMenu() {


	// 创建恢复窗口的菜单项
	//restoreAction = contextMenu->addAction("Restore");
	//connect(restoreAction, &QAction::triggered, this, &MainWindow::restoreWindow);

	// 创建退出菜单项
	exitAction = contextMenu->addAction("Exit");
	connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

	// 设置托盘菜单
	trayIcon->setContextMenu(contextMenu);

	// 设置托盘图标激活事件
	connect(trayIcon, &QSystemTrayIcon::activated, this, [this](QSystemTrayIcon::ActivationReason reason) {
		if (reason == QSystemTrayIcon::DoubleClick) { // 左键点击
			restoreWindow();
		}
		});

	trayIcon->show();
}

void MainWindow::restoreWindow() {
	// 恢复窗口显示
	showNormal();
	activateWindow();  // 使窗口获得焦点
	raise();  // 将窗口置顶

}

void MainWindow::showContextMenu(const QPoint& pos) {
	// 显示托盘菜单
	contextMenu->exec(mapToGlobal(pos));
}


void MainWindow::onChapterSelectClicked()
{
	QMap<int, QString> charIndexMap = tdm->tableModel()->menuIndexMap();

	ChapterDialog dialog(charIndexMap, this);
	connect(&dialog, &ChapterDialog::chapterSelected, this, &MainWindow::onChapterSelected);

	dialog.exec(); // 以模态方式显示
}

void MainWindow::onChapterSelected(int pageIndex)
{
	tdm->tableModel()->setCurrentPage(pageIndex);
	//textReaderManager->jumpToPage(pageIndex); // 让 Manager 通知 Model
	//emit pageChanged(pageIndex); // 让 View 更新
}