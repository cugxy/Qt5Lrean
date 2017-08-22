#include "udpclient.h"
#include <qmessagebox.h>

UDPClient::UDPClient(QWidget *parent, Qt::WindowFlags f)
	: QDialog(parent, f)
{
	setWindowTitle(tr("UDP client"));
	m_pText = new QTextEdit(this);
	m_pCloseBtn = new QPushButton(tr("close"), this);
	m_pMainLayout = new QVBoxLayout(this);

	m_pMainLayout->addWidget(m_pText);
	m_pMainLayout->addWidget(m_pCloseBtn);
	
	connect(m_pCloseBtn, SIGNAL(clicked()), this, SLOT(closeBtnClicked()));
	m_nPort = 5555;
	m_pUdpSocket = new QUdpSocket(this);
	connect(m_pUdpSocket, SIGNAL(readyRead()), this, SLOT(dataRecived()));

	bool bResult = m_pUdpSocket->bind(m_nPort);
	if (!bResult)
	{
		QMessageBox::information(this, tr("error"), tr("udp socket creat error"));
	}
}

UDPClient::~UDPClient()
{

}

void UDPClient::closeBtnClicked()
{
	close();
}

void UDPClient::dataRecived()
{
	while (m_pUdpSocket->hasPendingDatagrams())
	{
		QByteArray data;
		data.resize(m_pUdpSocket->pendingDatagramSize());
		m_pUdpSocket->readDatagram(data.data(), data.size());
		QString strMsg = QString::fromLocal8Bit(data.data());
		m_pText->setText(strMsg);
	}
}
