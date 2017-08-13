#include "geometry.h"

Geometry::Geometry(QWidget *parent)
	: QDialog(parent)
{
	setWindowTitle(tr("Geometry"));
	m_pXLabel = new QLabel(tr("X : "));
	m_pXValueLabel = new QLabel();
	m_pYLabel = new QLabel(tr("Y : "));
	m_pYValueLabel = new QLabel();
	m_pFrmLabel = new QLabel(tr("Frame : "));
	m_pFrmValueLabel = new QLabel(tr("X : "));
	m_pPosLabel = new QLabel(tr("Pos() : "));
	m_pPosValueLabel = new QLabel();
	m_pGeoLabel = new QLabel(tr("geometry : "));
	m_pGeoValueLabel = new QLabel();
	m_pWidthLabel = new QLabel(tr("width : "));
	m_pWidthValueLabel = new QLabel();
	m_pHeighLabel = new QLabel(tr("heigh : "));
	m_pHeighValueLabel = new QLabel();
	m_pRectLabel = new QLabel(tr("rect : "));
	m_pRectValueLabel = new QLabel();
	m_pSizeLabel = new QLabel(tr("size : "));
	m_pSizeValueLabel = new QLabel();

	m_pMainLayout = new QGridLayout(this);
	m_pMainLayout->addWidget(m_pXLabel, 0, 0);
	m_pMainLayout->addWidget(m_pXValueLabel, 0, 1);
	m_pMainLayout->addWidget(m_pYLabel, 1, 0);
	m_pMainLayout->addWidget(m_pYValueLabel, 1, 1);
	m_pMainLayout->addWidget(m_pFrmLabel, 2, 0);
	m_pMainLayout->addWidget(m_pFrmValueLabel, 2, 1);
	m_pMainLayout->addWidget(m_pPosLabel, 3, 0);
	m_pMainLayout->addWidget(m_pPosValueLabel, 3, 1);
	m_pMainLayout->addWidget(m_pGeoLabel, 4, 0);
	m_pMainLayout->addWidget(m_pGeoValueLabel, 4, 1);
	m_pMainLayout->addWidget(m_pWidthLabel, 5, 0);
	m_pMainLayout->addWidget(m_pWidthValueLabel, 5, 1);
	m_pMainLayout->addWidget(m_pHeighLabel, 6, 0);
	m_pMainLayout->addWidget(m_pHeighValueLabel, 6, 1);
	m_pMainLayout->addWidget(m_pRectLabel, 7, 0);
	m_pMainLayout->addWidget(m_pRectValueLabel, 7, 1);
	m_pMainLayout->addWidget(m_pSizeLabel, 8, 0);
	m_pMainLayout->addWidget(m_pSizeValueLabel, 8, 1);

	updataLabel();
}

Geometry::~Geometry()
{

}

void Geometry::updataLabel()
{
	QString strX;
	m_pXValueLabel->setText(strX.setNum(x()));
	QString strY;
	m_pYValueLabel->setText(strY.setNum(y()));

	QString strFrm;
	QString strTemp1, strTemp2, strTemp3, strTemp4;
	strFrm = strTemp1.setNum(frameGeometry().x()) + "," + strTemp2.setNum(frameGeometry().y()) + "," + strTemp3.setNum(frameGeometry().width()) + "," + strTemp4.setNum(frameGeometry().height());
	m_pFrmValueLabel->setText(strFrm);

	QString strPos;
	QString strTemp11, strTemp12;
	strPos = strTemp11.setNum(pos().x()) + "," + strTemp12.setNum(pos().y());
	m_pPosValueLabel->setText(strPos);

	QString strGeo;
	QString strTemp21, strTemp22, strTemp23, strTemp24;
	strGeo = strTemp21.setNum(geometry().x()) + "," + strTemp22.setNum(geometry().y()) + "," + strTemp23.setNum(geometry().width()) + "," + strTemp24.setNum(geometry().height());
	m_pGeoValueLabel->setText(strGeo);

	QString strWidth, strHeigh;
	m_pWidthValueLabel->setText(strWidth.setNum(width()));
	m_pHeighValueLabel->setText(strWidth.setNum(height()));

	QString strRect;
	QString strTemp31, strTemp32, strTemp33, strTemp34;
	strRect = strTemp31.setNum(rect().x()) + "," + strTemp32.setNum(rect().y()) + "," + strTemp33.setNum(rect().width()) + "," + strTemp34.setNum(rect().height());
	m_pRectValueLabel->setText(strRect);

	QString strSize;
	QString strTemp41, strTemp42;
	strSize = strTemp41.setNum(size().width()) + "," + strTemp42.setNum(size().height());
	m_pSizeValueLabel->setText(strSize);

}

void Geometry::moveEvent(QMoveEvent *)
{
	updataLabel();
}

void Geometry::resizeEvent(QResizeEvent *)
{
	updataLabel();
}
