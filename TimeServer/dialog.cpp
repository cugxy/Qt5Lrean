#include "dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qmessagebox.h>
#include "timeserver.h"

dialog::dialog(QWidget *parent)
	: QDialog(parent)
{
	setWindowTitle(tr("Time server"));
	m_pLabel1 = new QLabel(tr("port:"));
	m_pLabel2 = new QLabel();
	m_pQuitBtn = new QPushButton(tr("Quit"));

	QHBoxLayout * pBtnLayout = new QHBoxLayout();
	pBtnLayout->addStretch(1);
	pBtnLayout->addWidget(m_pQuitBtn);
	pBtnLayout->addStretch(1);

	QVBoxLayout * pMainLayout = new QVBoxLayout(this);
	pMainLayout->addWidget(m_pLabel1);
	pMainLayout->addWidget(m_pLabel2);
	pMainLayout->addLayout(pBtnLayout);

	connect(m_pQuitBtn, SIGNAL(clicked()), this, SLOT(close()));

	m_Count = 0;
	m_pServer = new TimeServer(this);
	if (!m_pServer->listen())
	{
		QMessageBox::critical(this, tr("server"), tr("can not start server %1").arg(m_pServer->errorString()));
		close();
		return;
	}
	m_pLabel1->setText(tr("Server port:%1").arg(m_pServer->serverPort()));
}

dialog::~dialog()
{

}

void dialog::slotShow()
{
	m_pLabel2->setText(tr("The %1 request finished").arg(++m_Count));
}
