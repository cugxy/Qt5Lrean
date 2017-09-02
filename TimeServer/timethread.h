#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QThread>
#include <qtcpsocket.h>


class TimeThread : public QThread
{
	Q_OBJECT

public:
	TimeThread(int socketDescriptor, QObject *parent = 0);
	~TimeThread();
	void run();
signals:
	void error(QTcpSocket::SocketError error);
private:
	int m_nSocketDescriptor;
};

#endif // TIMETHREAD_H
