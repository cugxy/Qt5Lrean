#include "paintarea.h"
#include <qpainter.h>
PaintArea::PaintArea(QWidget *parent)
	: QWidget(parent)
{
	setPalette(QPalette(Qt::white));
	setAutoFillBackground(true);
	setMinimumSize(400, 400);
}

PaintArea::~PaintArea()
{

}

void PaintArea::SetShape(Shape s)
{
	m_shape = s;
	update();
}

void PaintArea::SetPen(QPen p)
{
	m_Pen = p;
	update();
}

void PaintArea::SetBrush(QBrush b)
{
	m_Brush = b;
	update();
}

void PaintArea::SetFillRule(Qt::FillRule fillRule)
{
	m_FillRule = fillRule;
	update(); 
}  

void PaintArea::paintEvent(QPaintEvent * pPaintEvent)
{
	QPainter painter(this);
	painter.setPen(m_Pen);
	painter.setBrush(m_Brush);

	QRect rect(50, 100, 300, 200);

	static const QPoint point[4] =
	{
		QPoint(150, 100),
		QPoint(300, 150),
		QPoint(350, 250),
		QPoint(100, 300)
	};

	int startAngle = 30 * 16;
	int spanAngle = 120 * 16;

	QPainterPath path;
	path.addRect(150, 150, 100, 100);
	path.moveTo(100, 100);
	path.cubicTo(300, 100, 200, 200, 300, 300);
	path.cubicTo(100, 300, 200, 200, 100, 100);
	path.setFillRule(m_FillRule);

	switch (m_shape)
	{
	case EnuLine:
		painter.drawLine(rect.topLeft(), rect.bottomRight());
		break;
	case EnuRectangle:
		painter.drawRect(rect);
		break;
	case EnuRoundRect:
		painter.drawRoundRect(rect);
		break;
	case EnuEllipse:
		painter.drawEllipse(rect);
		break;
	case EnuPolygon:
		painter.drawPolygon(point, 4);
		break;
	case EnuPolyLine:
		painter.drawPolyline(point, 4);
		break;
	case EnuPoint:
		painter.drawPoints(point, 4);
		break;
	case EnuArc:
		painter.drawArc(rect, startAngle, spanAngle);
		break;
	case EnuPath:
		painter.drawPath(path);
		break;
	case EnuText:
		painter.drawText(rect, Qt::AlignCenter, tr("Hello Qt!"));
		break;
	case EnuPixmap:
		painter.drawPixmap(150, 150, QPixmap("image.png"));
		break;
	default:
		break;
	}
}
