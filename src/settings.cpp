#include "Settings.h"

Settings::Settings(QObject* parent) : QObject(parent)
{
	QString exeDir = QCoreApplication::applicationDirPath();
	// �����ļ�·��
	m_settingsFilePath = exeDir + "/settings.ini";
	// ����ʹ���Զ���·����QSettings
	m_settings = new QSettings(m_settingsFilePath, QSettings::IniFormat, this);

	if (!hasSettings()) {

		// ����Ĭ��ֵ
		setDefaults();
	}
	else if (hasSettings()) {	// ��������ļ��Ƿ���ڣ��������������
		loadSettings();
	}

	saveSettings();
}

Settings::~Settings()
{
	// �����������б�������
	saveSettings();
}

bool Settings::hasSettings() const
{
	// ��������ļ��Ƿ����
	QFileInfo checkFile(m_settingsFilePath);
	return checkFile.exists() && checkFile.isFile();

}
void Settings::setDefaults()
{
	// ����Ĭ��ֵ
	m_fontSize = 12;
	m_textSpacing = 1;
	m_lineSpacing = 1;
	m_novelPath = "";
	m_encoding = "UTF-8";
	m_menuEncoding = "UTF-8";
	m_linesPerPage = 20;
	m_opacity = 0.85;

}


void Settings::loadSettings()
{
	m_settings->beginGroup("Settings");
	// �������ļ���������
	m_fontSize = m_settings->value("fontSize", 12).toInt();
	m_textSpacing = m_settings->value("textSpacing", 1).toInt();
	m_lineSpacing = m_settings->value("lineSpacing", 1).toInt();
	m_novelPath = m_settings->value("novelPath", "").toString();
	m_encoding = m_settings->value("encoding", "UTF-8").toString();
	m_menuEncoding = m_settings->value("menuEncoding", "UTF-8").toString();
	m_linesPerPage = m_settings->value("linesPerPage", 20).toInt();
	m_opacity = m_settings->value("opacity", 0.85).toDouble();
	m_settings->endGroup();
}

void Settings::saveSettings()
{
	m_settings->beginGroup("Settings");
	// �������õ������ļ�
	m_settings->setValue("fontSize", m_fontSize);
	m_settings->setValue("textSpacing", m_textSpacing);
	m_settings->setValue("lineSpacing", m_lineSpacing);
	m_settings->setValue("novelPath", m_novelPath);
	m_settings->setValue("encoding", m_encoding);
	m_settings->setValue("menuEncoding", m_menuEncoding);
	m_settings->setValue("linesPerPage", m_linesPerPage);
	m_settings->setValue("opacity", m_opacity);
	// ����д�����
	m_settings->sync();
	m_settings->endGroup();
}

// ������ط���
void Settings::setFontSize(int size) {
	if (m_fontSize != size) {
		m_fontSize = size;
		//emit settingsChanged();
	}
}

void Settings::setTextSpacing(int spacing) {
	if (m_textSpacing != spacing) {
		m_textSpacing = spacing;
		//emit settingsChanged();
	}
}

void Settings::setLineSpacing(int spacing) {
	if (m_lineSpacing != spacing) {
		m_lineSpacing = spacing;
		//emit settingsChanged();
	}
}

void Settings::setNovelPath(const QString& path) {
	if (m_novelPath != path) {
		m_novelPath = path;
		//emit settingsChanged();
	}
}

void Settings::setEncoding(const QString& encoding) {
	if (m_encoding != encoding) {
		m_encoding = encoding;
		//emit settingsChanged();
	}
}

void Settings::setMenuEncoding(const QString& encoding) {
	if (m_menuEncoding != encoding) {
		m_menuEncoding = encoding;
		//emit settingsChanged();
	}
}

void Settings::setLinesPerPage(int lines) {
	if (m_linesPerPage != lines) {
		m_linesPerPage = lines;
		//emit settingsChanged();
	}
}

void Settings::setOpacity(double opa) {
	if (m_opacity != opa) {
		m_opacity = opa;
		emit settingsChanged();
	}
}

// ��ȡ��ط���
int Settings::getFontSize() const {
	return m_fontSize;
}

int Settings::getTextSpacing() const {
	return m_textSpacing;
}

int Settings::getLineSpacing() const {
	return m_lineSpacing;
}

QString Settings::getNovelPath() const {
	return m_novelPath;
}

QString Settings::getEncoding() const {
	return m_encoding;
}

QString Settings::getMenuEncoding() const {
	return m_menuEncoding;
}

int Settings::getLinesPerPage() const {
	return m_linesPerPage;
}

double Settings::getOpacity() const {
	return m_opacity;
}