#include "TextReaderView.h"
#include <QPainter>
#include <QFontMetrics>
#include <QApplication>
#include <QDebug>


bool isChineseCharacter(QChar ch) {
	return (ch.unicode() >= 0x4E00 && ch.unicode() <= 0x9FFF);

}

TextReaderView::TextReaderView(QWidget* parent)
	: QWidget(parent)
	, m_hotkeyView(nullptr)
	//, m_settings(nullptr)
	, m_resizeTimer(new QTimer(this))
	, m_contextMenu(new QMenu(this))
	, m_showPageNumber(0)
	, m_showProgress(0)
	, m_isDragging(false)
	, m_currentPage(0)
	, m_visibleLinesPerPage(0)
{

	//setWindowTitle("Text Reader");
	setWindowFlags(Qt::FramelessWindowHint);
	
	resize(600, 100);

	// ����Ĭ���������ɫ
	m_font = QFont("Times New Roman", 12);
	m_textColor = Qt::white;
	m_backgroundColor = QColor(0, 0, 0, 20);
	m_margins = QMargins(20, 20, 20, 20);

	// ���ô�������
	setFocusPolicy(Qt::StrongFocus);
	setAttribute(Qt::WA_TranslucentBackground);
	//setAttribute(Qt::WA_OpaquePaintEvent);
	setCursor(Qt::IBeamCursor);

	// �����ص�����С��ʱ��
	//m_resizeTimer->setSingleShot(true);
	//m_resizeTimer->setInterval(200); // 200ms�ӳ�
	//connect(m_resizeTimer, &QTimer::timeout, this, &TextReaderView::calculateLayout);
	// 
	// ���������Ĳ˵�
	createContextMenu();
	setupGlobalShortcut();
}

TextReaderView::~TextReaderView()
{
	// QObject�����Զ������Ӷ�������������
	if (m_hotkeyView) {
		delete m_hotkeyView;
		m_hotkeyView = nullptr;
	}
}

void TextReaderView::setFontSize(int size)
{
	m_fontSize = size;
	m_font.setPointSize(m_fontSize);
	update(); // ���»���
}

void TextReaderView::setTextSpacing(int spacing)
{
	m_textSpacing = spacing;
	update();
}

void TextReaderView::setLineSpacing(int spacing)
{
	m_lineSpacing = spacing;
	update();
}

void TextReaderView::showPage(const QString& text, int currentPage)
{
	m_currentPage = currentPage;
	m_formattedLines = formatText(text);
	refresh();
}

void TextReaderView::refresh()
{
	update();
}

void TextReaderView::setShowPageNumber(bool show)
{
	if (m_showPageNumber != show) {
		m_showPageNumber = show;
		update();
	}
}

void TextReaderView::setShowProgress(bool show)
{
	if (m_showProgress != show) {
		m_showProgress = show;
		update();
	}
}

void TextReaderView::setTotalPages(int totalPages) {
	m_totalPages = totalPages;  // �洢��ҳ��
	update();  // ���»��ƽ���
}

void TextReaderView::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::TextAntialiasing);

	// ���ư�͸���߿�
	//painter.setPen(Qt::NoPen);
	//painter.setBrush(QColor(0, 0, 0, 100)); // ��͸����ɫ
	//painter.drawRect(rect().adjusted(5, 5, -1, -1)); // ����1���صı߿�

	// ��䱳��
	painter.fillRect(rect(), m_backgroundColor);

	// �����ı�
	drawText(painter);

	// ����ҳ��ͽ�����Ϣ
	if (m_showPageNumber || m_showProgress) {
		drawPageInfo(painter);
	}
}

void TextReaderView::resizeEvent(QResizeEvent* event)
{
	Q_UNUSED(event);
	// ������ʱ�����ӳٴ���ߴ�仯
	m_resizeTimer->start();
}

void TextReaderView::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
		m_isDragging = false;
		m_dragStartPos = event->globalPos(); // ��¼��갴��ʱ��ȫ������
		m_windowStartPos = this->pos();      // ��¼���ڵ�ǰ����ʼλ��
	}
	QWidget::mousePressEvent(event);
}

void TextReaderView::mouseMoveEvent(QMouseEvent* event)
{
	if (!m_isDragging) { // �����ظ�������קģʽ
		QPoint delta = event->globalPos() - m_dragStartPos;
		if (delta.manhattanLength() > 10) { // ����10���ز��ж�Ϊ��ק
			m_isDragging = true;
		}
	}

	if (m_isDragging) {
		move(m_windowStartPos + (event->globalPos() - m_dragStartPos));
	}
}

void TextReaderView::mouseReleaseEvent(QMouseEvent* event)
{
	if (m_isDragging) {
		// �϶���������������ҳ
		m_isDragging = false;
	}
	else {
		// ������ҳ
		if (event->button() == Qt::LeftButton) {
			emit nextPageRequested();
		}
		else if (event->button() == Qt::RightButton) {
			emit previousPageRequested();
		}
	}
}


void TextReaderView::mouseDoubleClickEvent(QMouseEvent* event)
{
	// ����������ʵ��˫�����ܣ���ѡ�е��ʵ�
	QWidget::mouseDoubleClickEvent(event);
}




void TextReaderView::keyPressEvent(QKeyEvent* event)
{
	// ͸���ȵ�������
	const float opacityStep = 0.1;

	if (this->isVisible()) {

		switch (event->key()) {
			// ��ҳ��ذ���
		case Qt::Key_PageDown:
		case Qt::Key_Space:
		case Qt::Key_Right:
		case Qt::Key_Down:
			emit nextPageRequested();
			event->accept();
			break;
		case Qt::Key_PageUp:
		case Qt::Key_Backspace:
		case Qt::Key_Left:
		case Qt::Key_Up:
			emit previousPageRequested();
			event->accept();
			break;

		//	// ����͸���ȵİ���
		//case Qt::Key_Plus: // С���̼Ӻ�
		//case Qt::Key_Equal: // ��ͨ�Ӻţ����ã�
		//	// ����͸����
		//	setWindowOpacity(qMin(windowOpacity() + opacityStep, 1.0));
		//	event->accept();
		//	break;
		//case Qt::Key_Minus: // С���̼���
		//	// ����͸����
		//	setWindowOpacity(qMax(windowOpacity() - opacityStep, 0.1));
		//	event->accept();
		//	break;

		default:
			QWidget::keyPressEvent(event);
		}
	}
}


//void TextReaderView::wheelEvent(QWheelEvent* event)
//{
//	// �������¹�������һҳ
//	if (event->angleDelta().y() < 0) {
//		emit nextPageRequested();
//	}
//	// �������Ϲ�������һҳ
//	else if (event->angleDelta().y() > 0) {
//		emit previousPageRequested();
//	}
//	event->accept();
//}


void TextReaderView::drawText(QPainter& painter)
{
	// �����������ɫ
	painter.setFont(m_font);
	painter.setPen(m_textColor);

	// ��ȡ�ɻ�������
	QRect textArea = textRect();
	int lineHeight = QFontMetrics(m_font).height();

	//if (m_settings && m_settings->getLineSpacing() > 0) {
	//	lineHeight += m_settings->getLineSpacing();
	//}

	// ��ʽ����ǰҳ���ı�����,Ӧ�÷���Mrg
	//m_formattedLines = formatText(m_formattedLines);

	// �����ı���
	int y = textArea.top();
	for (const QString& line : m_formattedLines) {
		// ��������ɼ�����ֹͣ����
		if (y + lineHeight > textArea.bottom()) {
			break;
		}

		painter.drawText(textArea.left(), y + QFontMetrics(m_font).ascent(), line);
		y += lineHeight;
	}
}

void TextReaderView::drawPageInfo(QPainter& painter)
{

	painter.save();
	painter.setFont(QFont(m_font.family(), m_font.pointSize() - 2));
	painter.setPen(m_textColor);

	QRect footerRect = rect().adjusted(m_margins.left(), 0, -m_margins.right(), -10);
	footerRect.setTop(rect().bottom() - 30);

	QString pageInfo;
	int totalPages = m_totalPages;

	// ��ʾҳ��
	if (m_showPageNumber) {
		pageInfo = QString(DSL("�� %1/%2 ҳ")).arg(m_currentPage + 1).arg(totalPages);
	}

	// ��ʾ�Ķ�����
	if (m_showProgress) {
		int progress = totalPages > 0 ? ((m_currentPage + 1) * 100) / totalPages : 0;
		if (!pageInfo.isEmpty()) {
			pageInfo += " - ";
		}
		pageInfo += QString(DSL("����: %1%")).arg(progress);
	}

	// ���л���ҳ��ͽ�����Ϣ
	painter.drawText(footerRect, Qt::AlignCenter, pageInfo);
	painter.restore();
}


void TextReaderView::createContextMenu()
{


	QAction* actionShowPageNumber = m_contextMenu->addAction(DSL("��ʾҳ��"));
	actionShowPageNumber->setCheckable(true);
	actionShowPageNumber->setChecked(m_showPageNumber);
	connect(actionShowPageNumber, &QAction::toggled, this, &TextReaderView::setShowPageNumber);

	QAction* actionShowProgress = m_contextMenu->addAction(DSL("��ʾ����"));
	actionShowProgress->setCheckable(true);
	actionShowProgress->setChecked(m_showProgress);
	connect(actionShowProgress, &QAction::toggled, this, &TextReaderView::setShowProgress);

	// ���Ը�����Ҫ��Ӹ���˵���
}


QRect TextReaderView::textRect() const
{
	// ���ؿ����˱߾���ı�����
	return rect().adjusted(
		m_margins.left(),
		m_margins.top(),
		-m_margins.right(),
		-m_margins.bottom()
	);
}

QStringList TextReaderView::formatText(const QString& text) const
{
	QStringList lines;
	if (text.isEmpty()) return lines;

	QFontMetrics fm(m_font);
	int maxWidth = textRect().width();
	//int spacing = (m_settings ? m_settings->getTextSpacing() : 0);
	int spacing = 0;
	int spaceWidth = (spacing > 0) ? fm.horizontalAdvance(' ') : 0;

	// �Ƴ����пհ��ַ�
	QString cleanedText;
	for (const QChar& ch : text) {
		if (!ch.isSpace()) {
			cleanedText += ch;
		}
	}

	// �����з�����ʽ��
	QStringList paragraphs = cleanedText.split('\n');
	for (const QString& paragraph : paragraphs) {
		if (paragraph.isEmpty()) {
			lines.append("");
			continue;
		}

		QString currentLine;
		int currentWidth = 0;

		for (int i = 0; i < paragraph.length(); i++) {
			QChar ch = paragraph.at(i);
			int charWidth = fm.horizontalAdvance(ch);

			// ��������ַ��ͼ�����ܿ�ȣ����ڷ�ĩβ�ַ���Ӽ�ࣩ
			int additionalWidth = charWidth;
			if (spacing > 0 && !currentLine.isEmpty() && i < paragraph.length() - 1) {
				additionalWidth += spaceWidth * spacing;
			}

			// ����Ƿ���Ҫ����
			if (currentWidth + additionalWidth > maxWidth) {
				if (!currentLine.isEmpty()) {
					lines.append(currentLine);
					currentLine.clear();
					currentWidth = 0;
				}
				if (charWidth > maxWidth) {
					lines.append(ch); // ��������������ַ�����
					continue;
				}
			}

			currentLine += ch;
			currentWidth += charWidth; // ֻ�ۼ��ַ����
		}

		if (!currentLine.isEmpty()) {
			lines.append(currentLine);
		}
	}
	return lines;
}


void TextReaderView::setupGlobalShortcut()
{
	m_hotkeyView = new QHotkey(QKeySequence("Ctrl+Alt+M"), true, this);
	if (!m_hotkeyView->isRegistered()) {
		QMessageBox::warning(nullptr, "Warning", "hot key registration failed!");
	}

	QObject::connect(m_hotkeyView, &QHotkey::activated, this, &TextReaderView::toggleVisibility);
}

void TextReaderView::toggleVisibility()
{
	if (this->isVisible()) {
		this->hide();
	}
	else {
		this->show();
	}
}
