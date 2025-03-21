#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// 系统头文件
#include <QMainWindow>
#include <QLabel>
#include <QTextDocument>
#include <QSettings>
#include <QTextStream>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QEvent>
#include <QCloseEvent>

// 自定义头文件
#include "TextDocumentModel.h"
#include "TextReaderView.h"
#include "TextReaderManager.h"
#include "SettingsDialog.h"
#include "QHotkey.h" 
#include "chapterdialog.h"

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	// 构造函数和析构函数
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();


	void showChapterDialog();

protected:

	// 事件处理函数
	void closeEvent(QCloseEvent* event) override;
	void changeEvent(QEvent* event) override;

private:
	// 初始化界面
	void initUI();
	void initTrayIcon();
	void initHotkey();
	// 系统托盘辅助函数
	void createTrayMenu();
	void test();

	// 成员变量
	QLabel* textLabel;
	Settings* settings;
	SettingsDialog* settingsDialog;
	TextDocumentManager* tdm;
	TextDocumentModel* model;
	TextReaderView* view;

	// 系统托盘相关
	QSystemTrayIcon* trayIcon;
	QMenu* contextMenu;
	QAction* restoreAction;
	QAction* exitAction;
	QHotkey* m_hotkeyMainwindow;

private slots:
	// 槽函数
	void restoreWindow();
	void showContextMenu(const QPoint& pos);

	void onChapterSelectClicked();
	void onChapterSelected(int pageIndex);

};

#endif // MAINWINDOW_H