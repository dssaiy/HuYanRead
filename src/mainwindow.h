#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// ϵͳͷ�ļ�
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

// �Զ���ͷ�ļ�
#include "TextDocumentModel.h"
#include "TextReaderView.h"
#include "TextReaderManager.h"
#include "SettingsDialog.h"
#include "QHotkey.h" 
#include "chapterdialog.h"

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	// ���캯������������
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();


	void showChapterDialog();

protected:

	// �¼�������
	void closeEvent(QCloseEvent* event) override;
	void changeEvent(QEvent* event) override;

private:
	// ��ʼ������
	void initUI();
	void initTrayIcon();
	void initHotkey();
	// ϵͳ���̸�������
	void createTrayMenu();
	void test();

	// ��Ա����
	QLabel* textLabel;
	Settings* settings;
	SettingsDialog* settingsDialog;
	TextDocumentManager* tdm;
	TextDocumentModel* model;
	TextReaderView* view;

	// ϵͳ�������
	QSystemTrayIcon* trayIcon;
	QMenu* contextMenu;
	QAction* restoreAction;
	QAction* exitAction;
	QHotkey* m_hotkeyMainwindow;

private slots:
	// �ۺ���
	void restoreWindow();
	void showContextMenu(const QPoint& pos);

	void onChapterSelectClicked();
	void onChapterSelected(int pageIndex);

};

#endif // MAINWINDOW_H