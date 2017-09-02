#include "timethread.h"
#include <QDateTime>
#include <qbytearray.h>
#include <qdatastream.h>

TimeThread::TimeThread(int socketDescriptor, QObject *parent)
	: QThread(parent)
	,m_nSocketDescriptor(socketDescriptor)
{

}

TimeThread::~TimeThread()
{
	
}
void TimeThread::run()
{
	QTcpSocket tcpSocket;
	if (!tcpSocket.setSocketDescriptor(m_nSocketDescriptor))
	{
		emit error(tcpSocket.error());
		return;
	}
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_8);

	uint time2u = QDateTime::currentDateTime().toTime_t();
	out << time2u;

	tcpSocket.write(block);
	tcpSocket.disconnectFromHost();
	tcpSocket.waitForDisconnected();
}
