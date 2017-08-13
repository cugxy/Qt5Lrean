#pragma once
#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPen>
#include <QBrush>

class PaintArea : public QWidget
{
	Q_OBJECT

public:
	enum Shape
	{
		EnuLine,
		EnuRectangle,
		EnuRoundRect,
		EnuEllipse,
		EnuPolygon,
		EnuPolyLine, 
		EnuPoint,
		EnuArc,
		EnuPath,
		EnuText,
		EnuPixmap,
	};
	explicit PaintArea(QWidget *parent = 0);
	~PaintArea();
public:
	void SetShape(Shape);
	void SetPen(QPen);
	void SetBrush(QBrush);
	void SetFillRule(Qt::FillRule);
	void paintEvent(QPaintEvent *);



private:
	Shape m_shape;
	QPen m_Pen;
	QBrush m_Brush;
	Qt::FillRule m_FillRule;
};

#endif // PAINTAREA_H
