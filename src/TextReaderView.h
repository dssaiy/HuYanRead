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

	// ˢ�½���

	void showPage(const QString& text,int currentPage);

	void refresh();



public slots:

	// ��ʾ������ҳ��ͽ���
	void setShowPageNumber(bool show);
	void setShowProgress(bool show);

	// ������ҳ��
	void setTotalPages(int totalPages);  

signals:
	// �û������ź�
	void pageRequested(int page);
	void nextPageRequested();
	void previousPageRequested();
	void mouseClickedAt(const QPoint& pos);
	void contextMenuRequested(const QPoint& pos);

protected:
	// ��д�����¼�
	void paintEvent(QPaintEvent* event) override;

	// ��д�ߴ�仯�¼�
	void resizeEvent(QResizeEvent* event) override;

	// ��д����¼�
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseDoubleClickEvent(QMouseEvent* event) override;

	// ��д�����¼�
	void keyPressEvent(QKeyEvent* event) override;

	// ��д�����¼�
	//void wheelEvent(QWheelEvent* event) override;

	// ��д�����Ĳ˵��¼�
	//void contextMenuEvent(QContextMenuEvent* event) override;

private:
	// �����ı�����
	void drawText(QPainter& painter);

	// ����ҳ��ͽ���
	void drawPageInfo(QPainter& painter);

	// �����ı�����
	//void calculateLayout();

	// ���������Ĳ˵�
	void createContextMenu();

	// ����ɼ��ı�����
	QRect textRect() const;

	// ���ı���ʽ��Ϊ����
	QStringList formatText(const QString& text) const;

	void setupGlobalShortcut();

	void toggleVisibility();

private:

	//Settings* m_settings;             // ����

	QFont m_font;                     // ��ǰʹ�õ�����
	int m_fontSize;
	int m_textSpacing;
	int m_lineSpacing;
	QColor m_textColor;               // �ı���ɫ
	QColor m_backgroundColor;         // ������ɫ
	QMargins m_margins;               // �߾�

	QTimer* m_resizeTimer;            // �����ӳٴ���ߴ�仯
	QMenu* m_contextMenu;             // �����Ĳ˵�

	bool m_showPageNumber;            // �Ƿ���ʾҳ��
	bool m_showProgress;              // �Ƿ���ʾ����

	QStringList m_formattedLines;     // ��ʽ������ı���
	int m_visibleLinesPerPage;        // ÿҳ����ʾ������

	bool m_isDragging;                // �Ƿ������϶�
	QPoint m_dragStartPos;            // �϶���ʼλ��
	QPoint m_windowStartPos;            // �϶���ʼλ��

	int m_currentPage;                // ��ǰҳ��
	int m_totalPages;				  // ��ҳ��

	QHotkey* m_hotkeyView; // ��� QHotkey ��Ա����
};

#endif // TEXTREADERVIEW_H