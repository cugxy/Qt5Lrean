#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QtWidgets/QDialog>
#include <QLabel>
#include <qgridlayout.h>
class Geometry : public QDialog
{
	Q_OBJECT

public:
	Geometry(QWidget *parent = 0);
	~Geometry();
	void updataLabel();
private:
	QLabel * m_pXLabel;
	QLabel * m_pXValueLabel;
	QLabel * m_pYLabel;
	QLabel * m_pYValueLabel;
	QLabel * m_pFrmLabel;
	QLabel * m_pFrmValueLabel;
	QLabel * m_pPosLabel;
	QLabel * m_pPosValueLabel;
	QLabel * m_pGeoLabel;
	QLabel * m_pGeoValueLabel;
	QLabel * m_pWidthLabel;
	QLabel * m_pWidthValueLabel;
	QLabel * m_pHeighLabel;
	QLabel * m_pHeighValueLabel;
	QLabel * m_pRectLabel;
	QLabel * m_pRectValueLabel;
	QLabel * m_pSizeLabel;
	QLabel * m_pSizeValueLabel;
	QGridLayout * m_pMainLayout;

protected:
	void moveEvent(QMoveEvent*);
	void resizeEvent(QResizeEvent*);

};

#endif // GEOMETRY_H
