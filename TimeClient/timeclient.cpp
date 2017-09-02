#include "timeclient.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <qdatastream.h>
#include <qmessagebox.h>


TimeClient::TimeClient(QWidget *parent)
	: QDialog(parent)
{
	setWindowTitle(tr("client"));

	m_pServerNameLabel = new QLabel(tr("Server:"));
	m_pServerNameEdit = new QLineEdit("localhost");

	m_pPortLabel = new QLabel(tr("Port:"));
	m_pPortEdit = new QLineEdit();

	QGridLayout * pGridLayout = new QGridLayout();
	pGridLayout->addWidget(m_pServerNameLabel, 0, 0);
	pGridLayout->addWidget(m_pServerNameEdit, 0, 1);
	pGridLayout->addWidget(m_pPortLabel, 1, 0);
	pGridLayout->addWidget(m_pPortEdit, 1, 1);

	m_pTimeEdit = new QDateTimeEdit(this);
	QHBoxLayout * pHBLayout = new QHBoxLayout();
	pHBLayout->addWidget(m_pTimeEdit);

	m_pStartLabel = new QLabel(tr("Please start the server first"));
	QHBoxLayout * pHBLayout2 = new QHBoxLayout();
	pHBLayout2->addWidget(m_pStartLabel);

	m_pGetBtn = new QPushButton(tr("Get Time"));
	m_pGetBtn->setDefault(true);
	m_pGetBtn->setEnabled(false);
	m_pQuitBtn = new QPushButton(tr("Quit"));

	QHBoxLayout * pLayout3 = new QHBoxLayout();
	pLayout3->addStretch();
	pLayout3->addWidget(m_pGetBtn);
	pLayout3->addWidget(m_pQuitBtn);

	QVBoxLayout * pMainLayout = new QVBoxLayout(this);
	pMainLayout->addLayout(pGridLayout);
	pMainLayout->addLayout(pHBLayout);
	pMainLayout->addLayout(pHBLayout2);
	pMainLayout->addLayout(pLayout3);

	connect(m_pServerNameEdit, SIGNAL(textChanged(QString)), this, SLOT(enabelGetBtn()));
	connect(m_pPortEdit, SIGNAL(textChanged(QString)), this, SLOT(enabelGetBtn()));

	connect(m_pGetBtn, SIGNAL(clicked()), this, SLOT(getTime()));
	connect(m_pQuitBtn, SIGNAL(clicked()), this, SLOT(close()));

	m_pSocket = new QTcpSocket(this);


	m_pPortEdit->setFocus();

}

TimeClient::~TimeClient()
{

}

void TimeClient::enabelGetBtn()
{
	m_pGetBtn->setEnabled(!m_pServerNameEdit->text().isEmpty() && !m_pPortEdit->text().isEmpty());
}

void TimeClient::getTime()
{
	m_pGetBtn->setEnabled(false);
	m_Time2u = 0;
	m_pSocket->abort();
	int i = m_pPortEdit->text().toInt();
	m_pSocket->connectToHost(m_pServerNameEdit->text(), m_pPortEdit->text().toInt());
	connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(readTime()));
	connect(m_pSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(ShowError(QAbstractSocket::SocketError)));
}

void TimeClient::readTime()
{
	QDataStream in(m_pSocket);
	in.setVersion(QDataStream::Qt_5_8);
	if (m_Time2u == 0)
	{
		if (m_pSocket->bytesAvailable() < (int)sizeof(uint))
		{
			return;
		}
		in >> m_Time2u;
	}
	m_pTimeEdit->setDateTime(QDateTime::fromTime_t(m_Time2u));
	m_pGetBtn->setEnabled(true);
}

void TimeClient::ShowError(QAbstractSocket::SocketError error)
{
	switch (error)
	{
	case QAbstractSocket::RemoteHostClosedError:
		break;
	case QAbstractSocket::HostNotFoundError:
		QMessageBox::critical(this, tr("client"), tr("host not found"));
		break;
	default:
		QMessageBox::critical(this, tr("client"), tr("error %1").arg(m_pSocket->errorString()));

	}
}
