#ifndef THREADDLG_H
#define THREADDLG_H

#include <QtWidgets/QDialog>
#include <QPushButton>
#include "workthread.h"

class Threaddlg : public QDialog
{
	Q_OBJECT

public:
	Threaddlg(QWidget *parent = 0);
	~Threaddlg();

private:
	QPushButton * m_pStartBtn;
	QPushButton * m_pStopBtn;
	QPushButton * m_pQuitBtn;
private:
	WorkThread * m_pWorlThread[MAXSIZE];
	public slots :
	void slotStart();
	void slotStop();
};

#endif // THREADDLG_H
