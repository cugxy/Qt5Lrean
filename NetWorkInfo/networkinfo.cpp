#include <qhostinfo.h>
#include <qnetworkinterface.h>
#include "networkinfo.h"

NetWorkInfo::NetWorkInfo(QWidget *parent)
	: QWidget(parent)
{
	m_pHostLabel = new QLabel(tr("主机名："));
	m_pIPLabel = new QLabel(tr("IP："));
	m_pLoaclHostName = new QLineEdit();
	m_pIP = new QLineEdit();

	m_pDetailBtn = new QPushButton(tr("详细信息"));

	m_pMainLayout = new QGridLayout(this);
	m_pMainLayout->addWidget(m_pHostLabel, 0, 0);
	m_pMainLayout->addWidget(m_pLoaclHostName, 0, 1);
	m_pMainLayout->addWidget(m_pIPLabel, 1, 0);
	m_pMainLayout->addWidget(m_pIP, 1, 1);
	m_pMainLayout->addWidget(m_pDetailBtn, 2, 0, 1, 2);

	getHostInfo();
	connect(m_pDetailBtn, SIGNAL(clicked()), this, SLOT(slotDetail()));

}

NetWorkInfo::~NetWorkInfo()
{

}

void NetWorkInfo::getHostInfo() const
{
	QString strLocalhostName = QHostInfo::localHostName();
	m_pLoaclHostName->setText(strLocalhostName);

	QHostInfo info = QHostInfo::fromName(strLocalhostName);
	QList<QHostAddress> listAddr = info.addresses();
	if (!listAddr.isEmpty())
	{
		m_pIP->setText(listAddr.first().toString());
	}
}

void NetWorkInfo::slotDetail()
{
	QString strDetail = "";
	QList<QNetworkInterface> listNetInterface = QNetworkInterface::allInterfaces();
	for each (QNetworkInterface var in listNetInterface)
	{
		strDetail = strDetail + tr("设备") + var.name() + "\n";
		strDetail = strDetail + tr("硬件地址") + var.hardwareAddress() + "\n";
		QList<QNetworkAddressEntry> listEntry = var.addressEntries();
		foreach (QNetworkAddressEntry entry, listEntry)
		{
			strDetail = strDetail + "\t" + tr("IP地址") + entry.ip().toString() + "\n";
			strDetail = strDetail + "\t" + tr("子网掩码") + entry.netmask().toString() + "\n";
			strDetail = strDetail + "\t" + tr("广播地址") + entry.broadcast().toString() + "\n";
		}
	}
	QMessageBox::information(this, tr("Detail"), strDetail);
}
