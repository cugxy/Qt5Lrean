#include <math.h>
#include "Butterfly.h"

#define PI 3.1415926

Butterfly::Butterfly(QObject *parent)
{
	m_bUp = true;
	m_PixUp.load("E:/git/Qt5Lrean/x64/Debug/up.png");
	m_PixDown.load("E:/git/Qt5Lrean/x64/Debug/down.png");
	startTimer(10);
}


Butterfly::~Butterfly()
{
}

void Butterfly::timerEvent(QTimerEvent *pTimerEvent)
{
	qreal edgeX = scene()->sceneRect().right() + boundingRect().width() / 2;
	qreal edgeTop = scene()->sceneRect().top() + boundingRect().height() / 2;
	qreal edgeBtm = scene()->sceneRect().bottom() + boundingRect().height() / 2;

	if (pos().x() >= edgeX)
		setPos(scene()->sceneRect().left(), pos().y());
	if (pos().y() <= edgeTop)
		setPos(pos().x(), scene()->sceneRect().bottom());
	if (pos().y() >= edgeBtm)
		setPos(pos().x(), scene()->sceneRect().top());

	m_Angle += (qrand() % 10) / 20.0;
	qreal dx = fabs(sin(m_Angle  *PI) * 10.0);
	qreal dy = (qrand() % 20) - 10.0;

	setPos(mapToParent(dx, dy));
}

QRectF Butterfly::boundingRect() const
{
	qreal adjust = 2;
	return QRectF(
		-m_PixUp.width() / 2 - adjust, 
		-m_PixUp.height() / 2 - adjust,
		m_PixUp.width() + adjust * 2,
		m_PixUp.height() + adjust * 2
		);
}

void Butterfly::paint(QPainter * pPainter, const QStyleOptionGraphicsItem * pOption, QWidget * pWidget)
{
	if (m_bUp)
	{
		pPainter->drawPixmap(boundingRect().topLeft(), m_PixUp);
		m_bUp = !m_bUp;
	}
	else
	{
		pPainter->drawPixmap(boundingRect().topLeft(), m_PixDown);
		m_bUp = !m_bUp;
	}
}
