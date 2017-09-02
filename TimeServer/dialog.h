#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QDialog>
#include <qlabel.h>
#include <qpushbutton.h>

class TimeServer;
class dialog : public QDialog
{
	Q_OBJECT

public:
	dialog(QWidget *parent = 0);
	~dialog();
	public slots:
	void slotShow();
private:
	QLabel * m_pLabel1;
	QLabel * m_pLabel2;
	QPushButton * m_pQuitBtn;
	TimeServer * m_pServer;
	int m_Count;
};

#endif // DIALOG_H
