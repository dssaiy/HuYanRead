#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "SettingsDialog.h"
#include "Settings.h"

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);  // QApplication Ӧ���ڴ����κ� GUI ���֮ǰʵ����


	// �ڶԻ���رպ󴴽�����ʾ������
	MainWindow w;
	w.show();

	// �����¼�ѭ��
	return a.exec();
}
