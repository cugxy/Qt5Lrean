#include "threaddlg.h"
#include <QVBoxLayout>

Threaddlg::Threaddlg(QWidget *parent)
	: QDialog(parent)
{
	m_pStartBtn = new QPushButton(tr("Start"));
	m_pStopBtn = new QPushButton(tr("Stop"));
	m_pQuitBtn = new QPushButton(tr("Quit"));

	QVBoxLayout * pLayout = new QVBoxLayout(this);
	pLayout->addWidget(m_pStartBtn);
	pLayout->addWidget(m_pStopBtn);
	pLayout->addWidget(m_pQuitBtn);

	connect(m_pStartBtn, SIGNAL(clicked()), this, SLOT(slotStart()));
	connect(m_pStopBtn, SIGNAL(clicked()), this, SLOT(slotStop()));
	connect(m_pQuitBtn, SIGNAL(clicked()), this, SLOT(close()));

}

Threaddlg::~Threaddlg()
{

}
void Threaddlg::slotStart()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		m_pWorlThread[i] = new WorkThread();
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		m_pWorlThread[i]->start();
	}

	m_pStartBtn->setEnabled(false);
	m_pStopBtn->setEnabled(true);

}

void Threaddlg::slotStop()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		m_pWorlThread[i]->terminate();
		m_pWorlThread[i]->wait();
	}
	m_pStartBtn->setEnabled(true);
	m_pStopBtn->setEnabled(false);
}
