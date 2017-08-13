#pragma once
#ifndef PAINTEX_H
#define PAINTEX_H

#include <QtWidgets/QWidget>
#include "paintarea.h"
#include <qlabel.h>
#include <QComboBox>
#include <qspinbox.h>
#include <qpushbutton.h>
#include <qgridlayout.h>
#include <QGradient>


class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();

private:
	PaintArea * m_pPaintArea;

	QLabel *m_pShapeLabel;
	QComboBox * m_pShapeComboBox;
	QLabel * m_pPenWidthLabel;
	QSpinBox * m_pPenWidthSpinBox;
	QLabel * m_pPenColorLabel;
	QFrame * m_pPenColorFrame;
	QPushButton * m_pPenColorBtn;
	QLabel * m_pPenStyleLabel;
	QComboBox * m_pPenStyleComboBox;
	QLabel * m_pPenCapLabel;
	QComboBox * m_pPenCapComboBox;
	QLabel * m_pPenJoinLabel;
	QComboBox *m_pPenJoinComboBox;
	QLabel * m_pFillRuleLabel;
	QComboBox *m_pFillRuleComboBox;
	QLabel * m_pSpreadLabel;
	QComboBox *m_pSpreadComboBox;
	QGradient::Spread m_pSpread;
	QLabel * m_pBrushStyleLabel;
	QComboBox *m_pBrushStyleComboBox;
	QLabel * m_pBrushColorLabel;
	QFrame * m_pBrushColorFrame;
	QPushButton * m_pBrushColorBtn;

	QGridLayout * m_pRightLayout;
	protected slots:
	void ShowShape(int);
	void ShowPenWidth(int);
	void ShowPenColor();
	void ShowPenStyle(int); 
	void ShowPenCap(int);
	void ShowPenJoin(int);
	void ShowSpreadStyle(int);
	void ShowFillRule(int);
	void ShowBrushColor();
	void ShowBrush(int);
};

#endif // PAINTEX_H
