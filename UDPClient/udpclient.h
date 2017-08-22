#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <qtextedit.h>
#include <QVBoxLayout>
#include <qpushbutton.h>
#include <QtWidgets/QDialog>
#include <qudpsocket.h>

class UDPClient : public QDialog
{
	Q_OBJECT

public:
	UDPClient(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~UDPClient();
	public slots:
	void closeBtnClicked();
	void dataRecived();

private:
	QTextEdit * m_pText;
	QPushButton * m_pCloseBtn;
	QVBoxLayout * m_pMainLayout;
	int m_nPort;
	QUdpSocket * m_pUdpSocket;
};

#endif // UDPCLIENT_H
