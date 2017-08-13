#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include <QToolButton>
#include <QComboBox>
#include <QSpinBox>
#include "drawwidget.h"

class mainwindow : public QMainWindow
{
	Q_OBJECT

public:
	mainwindow(QWidget *parent = 0);
	~mainwindow();

	void createToolBar();

	public slots:
	void ShowStyle();
	void ShowColor();
private:
	DrawWidget *		m_pDrawWidget;
	QLabel *				m_pStyleLabel;
	QComboBox *		m_pStyleComboBox;
	QLabel *				m_pWidthLabel;
	QSpinBox *			m_pWidthSpinBox;
	QToolButton *		m_pColorBtn;
	QToolButton *		m_pClearBtn;

};

#endif // MAINWINDOW_H
