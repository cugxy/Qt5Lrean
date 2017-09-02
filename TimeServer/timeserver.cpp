#include "timeserver.h"
#include "timethread.h"
#include "dialog.h"
TimeServer::TimeServer(QObject *parent)
	: QTcpServer(parent)
{
	m_pDlg = (dialog*)parent;
	connect(this, SIGNAL(newConnection()), this, SLOT(newConnect()));
}

TimeServer::~TimeServer()
{

}

void TimeServer::newConnect()
{
	TimeThread * pThread = new TimeThread(0, nullptr);

	connect(pThread, SIGNAL(finished()), m_pDlg, SLOT(slotShow()));
	connect(pThread, SIGNAL(finished()), pThread, SLOT(deleteLater()), Qt::DirectConnection);
	pThread->start();
}

