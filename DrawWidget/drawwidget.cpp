#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent)
	: QWidget(parent)
{
	setAutoFillBackground(true);
	setPalette(QPalette(Qt::white));
	m_pPix = new QPixmap(size());
	m_pPix->fill(Qt::blue);
	setMinimumSize(600, 400);
}

DrawWidget::~DrawWidget()
{

}

void DrawWidget::mousePressEvent(QMouseEvent *e)
{
	m_StartPoint = e->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *e)
{
	QPainter *pPainter = new QPainter();

	QPen pen;
	pen.setStyle(Qt::PenStyle(m_nStyle));
	pen.setWidth(m_nWidth);
	pen.setColor(m_Color);

	pPainter->begin(m_pPix);
	pPainter->setPen(pen);
	pPainter->drawLine(m_StartPoint, e->pos());
	pPainter->end();
	m_StartPoint = e->pos();
	update();
}

void DrawWidget::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.drawPixmap(QPoint(0, 0), *m_pPix);
}

void DrawWidget::resizeEvent(QResizeEvent *e)
{
	if (height() > m_pPix->height() || width() > m_pPix->width())
	{
		QPixmap *pNewPix = new QPixmap(size());
		pNewPix->fill(Qt::blue);
		QPainter painter(pNewPix);
		painter.drawPixmap(QPoint(0, 0), *pNewPix);
		m_pPix = pNewPix;
	}
	QWidget::resizeEvent(e);
}

void DrawWidget::setStyle(int nStyle)
{
	m_nStyle = nStyle;
}

void DrawWidget::setWidth(int nWidth)
{
	m_nWidth = nWidth;
}

void DrawWidget::setColor(QColor c)
{
	m_Color = c;
}

void DrawWidget::clear()
{
	QPixmap *pClearPix = new QPixmap(size());
	pClearPix->fill(Qt::blue);
	m_pPix = pClearPix;
	update();
}
