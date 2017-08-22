#include "udpserver.h"
#include <QHostAddress>

UDPServer::UDPServer(QWidget *parent, Qt::WindowFlags f)
	: QDialog(parent, f)
{
	setWindowTitle(tr("UDP Server"));

	m_pTimerLabel = new QLabel(tr("计时器："), this);
	m_pText = new QLineEdit(this);
	m_pStartBtn = new QPushButton(tr("开始"), this);

	m_pMainLayout = new QVBoxLayout(this);
	m_pMainLayout->addWidget(m_pTimerLabel);
	m_pMainLayout->addWidget(m_pText);
	m_pMainLayout->addWidget(m_pStartBtn);


	m_nPort = 5555;
	m_bIsStarted = false;
	m_pUdpSocket = new QUdpSocket(this);
	m_pTimer = new QTimer(this);

	connect(m_pStartBtn, SIGNAL(clicked()), this, SLOT(OnClickStartBtn()));
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(timeOut()));
}

UDPServer::~UDPServer()
{

}

void UDPServer::timeOut()
{
	QString strMsg = m_pText->text();
	int nLen = 0;
	if ("" == strMsg)
	{
		return;
	}
	if ((nLen = m_pUdpSocket->writeDatagram(strMsg.toLocal8Bit(), strMsg.length(), QHostAddress::Broadcast, m_nPort)) != strMsg.length())
	{
		return;
	}
}
void UDPServer::OnClickStartBtn()
{
	if (!m_bIsStarted)
	{
		m_pStartBtn->setText(tr("停止"));
		m_pTimer->start(100);
		m_bIsStarted = !m_bIsStarted;
	}
	else
	{
		m_pStartBtn->setText(tr("开始"));
		m_pTimer->stop();
		m_bIsStarted = !m_bIsStarted;
	}
}