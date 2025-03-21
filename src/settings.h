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
	// 设置相关方法

	void setFontSize(int size); // 设置字体大小
	void setTextSpacing(int spacing); // 设置文本间距
	void setLineSpacing(int spacing); // 设置行距
	void setNovelPath(const QString& path); // 设置小说路径
	void setEncoding(const QString& encoding); // 设置编码
	void setMenuEncoding(const QString& encoding); // 设置目录编码
	void setLinesPerPage(int lines); // 设置每页显示的文本行数
	void setOpacity(double opa);

	// 获取设置的方法

	int getFontSize() const; // 获取字体大小
	int getTextSpacing() const; // 获取文本间距
	int getLineSpacing() const; // 获取行距
	QString getNovelPath() const; // 获取小说路径
	QString getEncoding() const; // 获取编码
	QString getMenuEncoding() const; // 获取编码
	int getLinesPerPage() const; // 获取每页文本行数
	double getOpacity() const;

	QSettings* getpSettings() { return m_settings; }

	// 保存和加载设置
	void saveSettings(); // 保存设置到文件
	void loadSettings(); // 从文件加载设置
	bool hasSettings() const; // 检查配置文件是否存在

signals:
	void settingsChanged(); // 设置改变信号

private:

	// 设置默认值
	void setDefaults();

	int m_fontSize;           // 字体大小
	int m_textSpacing;        // 文本间距
	int m_lineSpacing;        // 行间距
	QString m_novelPath;      // 小说路径
	QString m_encoding;       // 编码
	QString m_menuEncoding;       ///< 目录检索文件编码
	int m_linesPerPage;       // 每页显示的文本数

	QSettings* m_settings;    // 设置对象
	QString m_settingsFilePath; // 配置文件路径

	double m_opacity;          // 透明度
};



