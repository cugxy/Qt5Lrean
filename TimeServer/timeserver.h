#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QTcpServer>
class dialog;

class TimeServer : public QTcpServer
{
	Q_OBJECT

public:
	TimeServer(QObject *parent = 0);
	~TimeServer();
protected:
	void incomingConnection(int socketDercriptor);
private:
	dialog * m_pDlg;
};

#endif // TIMESERVER_H
