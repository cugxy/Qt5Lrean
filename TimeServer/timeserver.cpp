#include "timeserver.h"
#include "timethread.h"
#include "dialog.h"
TimeServer::TimeServer(QObject *parent)
	: QTcpServer(parent)
{
	m_pDlg = (dialog*)parent;
}

TimeServer::~TimeServer()
{

}

void TimeServer::incomingConnection(int socketDercriptor)
{
	TimeThread * pThread = new TimeThread(socketDercriptor, nullptr);

	connect(pThread, SIGNAL(finished()), m_pDlg, SLOT(slotShow()));
	connect(pThread, SIGNAL(finished()), pThread, SLOT(deleteLater()), Qt::DirectConnection);
	pThread->start();
}
