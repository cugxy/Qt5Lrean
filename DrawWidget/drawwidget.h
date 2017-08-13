#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <qwidget.h>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QColor>
#include <QPixmap>
#include <qpoint.h>
#include <QPainter>
#include <QPalette>

class DrawWidget : public QWidget
{
	Q_OBJECT

public:
	explicit DrawWidget(QWidget *parent = 0);
	~DrawWidget();

	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);
signals:

	public slots :

	void setStyle(int);
	void setWidth(int);
	void setColor(QColor);
	void clear();

private:
	QPixmap *	m_pPix;
	QPoint 		m_StartPoint;
	QPoint 		m_EndPoint;
	int					m_nStyle;
	int					m_nWidth;
	QColor 		m_Color;
};

#endif // DRAWWIDGET_H
