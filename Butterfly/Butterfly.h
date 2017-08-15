#pragma once
#include "qobject.h"
#include <qgraphicsitem.h>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
class Butterfly : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	explicit Butterfly(QObject *parent = 0);
	virtual ~Butterfly();

	void timerEvent(QTimerEvent*);
	QRectF boundingRect()const;
protected:
	void paint(QPainter * pPainter, const QStyleOptionGraphicsItem * pOption, QWidget * pWidget);

private:
	bool m_bUp;
	QPixmap m_PixUp;
	QPixmap m_PixDown;
	qreal m_Angle;
};

