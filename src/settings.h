#pragma once
#include <QObject>
#include <QString>
#include <QColor>
#include <QSettings>
#include <QDir>
#include <QCoreApplication>
#include <QFileInfo>

class Settings : public QObject {
	Q_OBJECT

public:
	explicit Settings(QObject* parent = nullptr);

	~Settings();
	// ������ط���

	void setFontSize(int size); // ���������С
	void setTextSpacing(int spacing); // �����ı����
	void setLineSpacing(int spacing); // �����о�
	void setNovelPath(const QString& path); // ����С˵·��
	void setEncoding(const QString& encoding); // ���ñ���
	void setMenuEncoding(const QString& encoding); // ����Ŀ¼����
	void setLinesPerPage(int lines); // ����ÿҳ��ʾ���ı�����
	void setOpacity(double opa);

	// ��ȡ���õķ���

	int getFontSize() const; // ��ȡ�����С
	int getTextSpacing() const; // ��ȡ�ı����
	int getLineSpacing() const; // ��ȡ�о�
	QString getNovelPath() const; // ��ȡС˵·��
	QString getEncoding() const; // ��ȡ����
	QString getMenuEncoding() const; // ��ȡ����
	int getLinesPerPage() const; // ��ȡÿҳ�ı�����
	double getOpacity() const;

	QSettings* getpSettings() { return m_settings; }

	// ����ͼ�������
	void saveSettings(); // �������õ��ļ�
	void loadSettings(); // ���ļ���������
	bool hasSettings() const; // ��������ļ��Ƿ����

signals:
	void settingsChanged(); // ���øı��ź�

private:

	// ����Ĭ��ֵ
	void setDefaults();

	int m_fontSize;           // �����С
	int m_textSpacing;        // �ı����
	int m_lineSpacing;        // �м��
	QString m_novelPath;      // С˵·��
	QString m_encoding;       // ����
	QString m_menuEncoding;       ///< Ŀ¼�����ļ�����
	int m_linesPerPage;       // ÿҳ��ʾ���ı���

	QSettings* m_settings;    // ���ö���
	QString m_settingsFilePath; // �����ļ�·��

	double m_opacity;          // ͸����
};



