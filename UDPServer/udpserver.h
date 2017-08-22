#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QDialog>
#include <QLabel>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QVBoxLayout>
#include <qudpsocket.h>
#include <qtimer.h>

class UDPServer : public QDialog
{
	Q_OBJECT

public:
	UDPServer(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~UDPServer();

private:
	QLabel * m_pTimerLabel;
	QLineEdit * m_pText;
	QPushButton * m_pStartBtn;
	QVBoxLayout * m_pMainLayout;

	public slots:
	void OnClickStartBtn();
	void timeOut();
private:
	int m_nPort;
	bool m_bIsStarted;
	QUdpSocket * m_pUdpSocket;
	QTimer * m_pTimer;
};

#endif // UDPSERVER_H
