#ifndef NETWORKINFO_H
#define NETWORKINFO_H

#include <QtWidgets/QWidget>
#include <QLabel>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qgridlayout.h>
#include <qmessagebox.h>
class NetWorkInfo : public QWidget
{
	Q_OBJECT

public:
	NetWorkInfo(QWidget *parent = 0);
	~NetWorkInfo();
	void getHostInfo()const;
	public slots:
	void slotDetail();
private:
	QLabel * m_pHostLabel;
	QLineEdit * m_pLoaclHostName;
	QLabel * m_pIPLabel;
	QLineEdit * m_pIP;

	QPushButton * m_pDetailBtn;
	QGridLayout * m_pMainLayout;
};

#endif // NETWORKINFO_H
