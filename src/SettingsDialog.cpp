#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"
#include <QFileDialog>

SettingsDialog::SettingsDialog(Settings* settings, QWidget* parent)
	: QDialog(parent), m_settings(settings), ui(new Ui::SettingsDialog) {
	ui->setupUi(this);
	setWindowTitle("Settings");

	connect(ui->selectPathButton, &QPushButton::clicked, this, &SettingsDialog::selectNovelPath);
	connect(ui->applyButton, &QPushButton::clicked, this, &SettingsDialog::applySettings);
	connect(ui->cancelButton, &QPushButton::clicked, this, [this]() {
		loadSettings();  // 先调用 loadSettings
		reject();        // 然后关闭对话框
		});

	loadSettings();
}

SettingsDialog::~SettingsDialog() {
	delete ui;
}

//menuEncodingLineEdit

void SettingsDialog::loadSettings() {
	ui->fontSizeSpinBox->setValue(m_settings->getFontSize());
	ui->textSpacingSpinBox->setValue(m_settings->getTextSpacing());
	ui->lineSpacingSpinBox->setValue(m_settings->getLineSpacing());
	ui->novelPathLineEdit->setText(m_settings->getNovelPath());
	ui->encodingLineEdit->setCurrentText(m_settings->getEncoding());
	ui->menuEncodingLineEdit->setCurrentText(m_settings->getMenuEncoding());
	ui->linesPerPageSpinBox->setValue(m_settings->getLinesPerPage());
	ui->opacitySpinBox->setValue(m_settings->getOpacity());
}

void SettingsDialog::applySettings() {
	m_settings->setFontSize(ui->fontSizeSpinBox->value());
	m_settings->setTextSpacing(ui->textSpacingSpinBox->value());
	m_settings->setLineSpacing(ui->lineSpacingSpinBox->value());
	m_settings->setNovelPath(ui->novelPathLineEdit->text());
	m_settings->setEncoding(ui->encodingLineEdit->currentText());
	m_settings->setMenuEncoding(ui->menuEncodingLineEdit->currentText());
	m_settings->setLinesPerPage(ui->linesPerPageSpinBox->value());
	m_settings->setOpacity(ui->opacitySpinBox->value());

	m_settings->saveSettings();

	emit m_settings->settingsChanged();
	accept();
}

void SettingsDialog::selectNovelPath() {
	QString path = QFileDialog::getOpenFileName(this, "Select Novel File", "", "Text Files (*.txt);;All Files (*)");
	if (!path.isEmpty()) {
		ui->novelPathLineEdit->setText(path);
	}
}
