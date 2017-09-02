#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QMainWindow(parent)
	,ui(new Ui_WidgetClass())
{
	ui->setupUi(this);
	setFixedSize(750, 500);
	createMenuBar();
}

Widget::~Widget()
{

}

void Widget::slotOnManageMenuClicked()
{
	ui->managerPage->setCurrentIndex(0);
}

void Widget::slotOnChartMenuClicked()
{
	ui->managerPage->setCurrentIndex(1);
}

void Widget::slotOnQuitMenuClicked()
{
	this->close();
}

void Widget::createMenuBar()
{
	m_pManageAct = new QAction(tr("Ʒ�Ƴ�����"), this);
	m_pChartAct = new QAction(tr("����ͳ��"), this);
	m_pQuitAct = new QAction(tr("�˳�"), this);

	m_pManageAct->setShortcut(tr("Crtl+M"));
	m_pChartAct->setShortcut(tr("Crtl+C"));
	m_pQuitAct->setShortcut(tr("Crtl+Q"));

	m_pManageMenu = menuBar()->addMenu(tr("���۹���"));
	m_pManageMenu->addAction(m_pManageAct);
	m_pManageMenu->addAction(m_pChartAct);
	m_pManageMenu->addSeparator();
	m_pManageMenu->addAction(m_pQuitAct);

	m_pPasswordMenu = menuBar()->addMenu(tr("�޸�����"));

	connect(m_pManageAct, SIGNAL(triggered()), this, SLOT(slotOnManageMenuClicked()));
	connect(m_pChartAct, SIGNAL(triggered()), this, SLOT(slotOnChartMenuClicked()));
	connect(m_pQuitAct, SIGNAL(triggered()), this, SLOT(slotOnQuitMenuClicked()));
}
