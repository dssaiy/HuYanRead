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

	// 设置默认字体和颜色
	m_font = QFont("Times New Roman", 12);
	m_textColor = Qt::white;
	m_backgroundColor = QColor(0, 0, 0, 20);
	m_margins = QMargins(20, 20, 20, 20);

	// 设置窗口属性
	setFocusPolicy(Qt::StrongFocus);
	setAttribute(Qt::WA_TranslucentBackground);
	//setAttribute(Qt::WA_OpaquePaintEvent);
	setCursor(Qt::IBeamCursor);

	// 配置重调整大小定时器
	//m_resizeTimer->setSingleShot(true);
	//m_resizeTimer->setInterval(200); // 200ms延迟
	//connect(m_resizeTimer, &QTimer::timeout, this, &TextReaderView::calculateLayout);
	// 
	// 创建上下文菜单
	createContextMenu();
	setupGlobalShortcut();
}

TextReaderView::~TextReaderView()
{
	// QObject树会自动清理子对象，无需额外操作
	if (m_hotkeyView) {
		delete m_hotkeyView;
		m_hotkeyView = nullptr;
	}
}

void TextReaderView::setFontSize(int size)
{
	m_fontSize = size;
	m_font.setPointSize(m_fontSize);
	update(); // 重新绘制
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
	m_totalPages = totalPages;  // 存储总页数
	update();  // 重新绘制界面
}

void TextReaderView::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::TextAntialiasing);

	// 绘制半透明边框
	//painter.setPen(Qt::NoPen);
	//painter.setBrush(QColor(0, 0, 0, 100)); // 半透明黑色
	//painter.drawRect(rect().adjusted(5, 5, -1, -1)); // 留出1像素的边框

	// 填充背景
	painter.fillRect(rect(), m_backgroundColor);

	// 绘制文本
	drawText(painter);

	// 绘制页码和进度信息
	if (m_showPageNumber || m_showProgress) {
		drawPageInfo(painter);
	}
}

void TextReaderView::resizeEvent(QResizeEvent* event)
{
	Q_UNUSED(event);
	// 启动定时器，延迟处理尺寸变化
	m_resizeTimer->start();
}

void TextReaderView::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
		m_isDragging = false;
		m_dragStartPos = event->globalPos(); // 记录鼠标按下时的全局坐标
		m_windowStartPos = this->pos();      // 记录窗口当前的起始位置
	}
	QWidget::mousePressEvent(event);
}

void TextReaderView::mouseMoveEvent(QMouseEvent* event)
{
	if (!m_isDragging) { // 避免重复进入拖拽模式
		QPoint delta = event->globalPos() - m_dragStartPos;
		if (delta.manhattanLength() > 10) { // 超过10像素才判定为拖拽
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
		// 拖动结束，不触发翻页
		m_isDragging = false;
	}
	else {
		// 触发翻页
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
	// 可以在这里实现双击功能，如选中单词等
	QWidget::mouseDoubleClickEvent(event);
}




void TextReaderView::keyPressEvent(QKeyEvent* event)
{
	// 透明度调整步长
	const float opacityStep = 0.1;

	if (this->isVisible()) {

		switch (event->key()) {
			// 翻页相关按键
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

		//	// 调整透明度的按键
		//case Qt::Key_Plus: // 小键盘加号
		//case Qt::Key_Equal: // 普通加号（备用）
		//	// 增加透明度
		//	setWindowOpacity(qMin(windowOpacity() + opacityStep, 1.0));
		//	event->accept();
		//	break;
		//case Qt::Key_Minus: // 小键盘减号
		//	// 减少透明度
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
//	// 滚轮向下滚动，下一页
//	if (event->angleDelta().y() < 0) {
//		emit nextPageRequested();
//	}
//	// 滚轮向上滚动，上一页
//	else if (event->angleDelta().y() > 0) {
//		emit previousPageRequested();
//	}
//	event->accept();
//}


void TextReaderView::drawText(QPainter& painter)
{
	// 设置字体和颜色
	painter.setFont(m_font);
	painter.setPen(m_textColor);

	// 获取可绘制区域
	QRect textArea = textRect();
	int lineHeight = QFontMetrics(m_font).height();

	//if (m_settings && m_settings->getLineSpacing() > 0) {
	//	lineHeight += m_settings->getLineSpacing();
	//}

	// 格式化当前页的文本内容,应该放入Mrg
	//m_formattedLines = formatText(m_formattedLines);

	// 绘制文本行
	int y = textArea.top();
	for (const QString& line : m_formattedLines) {
		// 如果超出可见区域，停止绘制
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

	// 显示页码
	if (m_showPageNumber) {
		pageInfo = QString(DSL("第 %1/%2 页")).arg(m_currentPage + 1).arg(totalPages);
	}

	// 显示阅读进度
	if (m_showProgress) {
		int progress = totalPages > 0 ? ((m_currentPage + 1) * 100) / totalPages : 0;
		if (!pageInfo.isEmpty()) {
			pageInfo += " - ";
		}
		pageInfo += QString(DSL("进度: %1%")).arg(progress);
	}

	// 居中绘制页码和进度信息
	painter.drawText(footerRect, Qt::AlignCenter, pageInfo);
	painter.restore();
}


void TextReaderView::createContextMenu()
{


	QAction* actionShowPageNumber = m_contextMenu->addAction(DSL("显示页码"));
	actionShowPageNumber->setCheckable(true);
	actionShowPageNumber->setChecked(m_showPageNumber);
	connect(actionShowPageNumber, &QAction::toggled, this, &TextReaderView::setShowPageNumber);

	QAction* actionShowProgress = m_contextMenu->addAction(DSL("显示进度"));
	actionShowProgress->setCheckable(true);
	actionShowProgress->setChecked(m_showProgress);
	connect(actionShowProgress, &QAction::toggled, this, &TextReaderView::setShowProgress);

	// 可以根据需要添加更多菜单项
}


QRect TextReaderView::textRect() const
{
	// 返回考虑了边距的文本区域
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

	// 移除所有空白字符
	QString cleanedText;
	for (const QChar& ch : text) {
		if (!ch.isSpace()) {
			cleanedText += ch;
		}
	}

	// 处理换行符并格式化
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

			// 计算添加字符和间距后的总宽度（仅在非末尾字符后加间距）
			int additionalWidth = charWidth;
			if (spacing > 0 && !currentLine.isEmpty() && i < paragraph.length() - 1) {
				additionalWidth += spaceWidth * spacing;
			}

			// 检查是否需要换行
			if (currentWidth + additionalWidth > maxWidth) {
				if (!currentLine.isEmpty()) {
					lines.append(currentLine);
					currentLine.clear();
					currentWidth = 0;
				}
				if (charWidth > maxWidth) {
					lines.append(ch); // 极端情况：单个字符超宽
					continue;
				}
			}

			currentLine += ch;
			currentWidth += charWidth; // 只累加字符宽度
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
