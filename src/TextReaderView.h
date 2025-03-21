#ifndef TEXTREADERVIEW_H
#define TEXTREADERVIEW_H

#include <QWidget>
#include <QPainter>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QFontMetrics>
#include <QMessagebox>

#include "TextDocumentModel.h"
#include "Settings.h"
#include "QHotkey.h" 

#define DSL(str) QStringLiteral(str)

class TextReaderView : public QWidget
{
	Q_OBJECT

public:
	explicit TextReaderView(QWidget* parent = nullptr);
	~TextReaderView();

	void setFontSize(int size);

	void setTextSpacing(int spacing);

	void setLineSpacing(int spacing);

	// 刷新界面

	void showPage(const QString& text,int currentPage);

	void refresh();



public slots:

	// 显示或隐藏页码和进度
	void setShowPageNumber(bool show);
	void setShowProgress(bool show);

	// 更新总页数
	void setTotalPages(int totalPages);  

signals:
	// 用户交互信号
	void pageRequested(int page);
	void nextPageRequested();
	void previousPageRequested();
	void mouseClickedAt(const QPoint& pos);
	void contextMenuRequested(const QPoint& pos);

protected:
	// 重写绘制事件
	void paintEvent(QPaintEvent* event) override;

	// 重写尺寸变化事件
	void resizeEvent(QResizeEvent* event) override;

	// 重写鼠标事件
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseDoubleClickEvent(QMouseEvent* event) override;

	// 重写键盘事件
	void keyPressEvent(QKeyEvent* event) override;

	// 重写滚轮事件
	//void wheelEvent(QWheelEvent* event) override;

	// 重写上下文菜单事件
	//void contextMenuEvent(QContextMenuEvent* event) override;

private:
	// 绘制文本内容
	void drawText(QPainter& painter);

	// 绘制页码和进度
	void drawPageInfo(QPainter& painter);

	// 计算文本布局
	//void calculateLayout();

	// 创建上下文菜单
	void createContextMenu();

	// 计算可见文本区域
	QRect textRect() const;

	// 将文本格式化为多行
	QStringList formatText(const QString& text) const;

	void setupGlobalShortcut();

	void toggleVisibility();

private:

	//Settings* m_settings;             // 设置

	QFont m_font;                     // 当前使用的字体
	int m_fontSize;
	int m_textSpacing;
	int m_lineSpacing;
	QColor m_textColor;               // 文本颜色
	QColor m_backgroundColor;         // 背景颜色
	QMargins m_margins;               // 边距

	QTimer* m_resizeTimer;            // 用于延迟处理尺寸变化
	QMenu* m_contextMenu;             // 上下文菜单

	bool m_showPageNumber;            // 是否显示页码
	bool m_showProgress;              // 是否显示进度

	QStringList m_formattedLines;     // 格式化后的文本行
	int m_visibleLinesPerPage;        // 每页可显示的行数

	bool m_isDragging;                // 是否正在拖动
	QPoint m_dragStartPos;            // 拖动起始位置
	QPoint m_windowStartPos;            // 拖动起始位置

	int m_currentPage;                // 当前页码
	int m_totalPages;				  // 总页码

	QHotkey* m_hotkeyView; // 添加 QHotkey 成员变量
};

#endif // TEXTREADERVIEW_H