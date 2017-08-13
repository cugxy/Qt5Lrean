#include "mainwindow.h"
#include <qtoolbar.h>
#include <qcolordialog.h>

mainwindow::mainwindow(QWidget *parent)
	: QMainWindow(parent)
{
	m_pDrawWidget = new DrawWidget();
	setCentralWidget(m_pDrawWidget);

	createToolBar();

	setMinimumSize(600, 400);

	ShowStyle();
	m_pDrawWidget->setColor(Qt::black);
	m_pDrawWidget->setWidth(m_pWidthSpinBox->value());
}

mainwindow::~mainwindow()
{

}


void mainwindow::createToolBar()
{
	QToolBar * pToolBar = addToolBar("Tool");  
	m_pStyleLabel = new QLabel(tr("lint style:"));
	m_pStyleComboBox = new QComboBox();
	m_pStyleComboBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
	m_pStyleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
	m_pStyleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
	m_pStyleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
	m_pStyleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
	connect(m_pStyleComboBox, SIGNAL(activated()), this, SLOT(ShowStyle()));

	m_pWidthLabel = new QLabel(tr("Line Width:"));
	m_pWidthSpinBox = new QSpinBox;
	connect(m_pWidthSpinBox, SIGNAL(valueChanged(int)), m_pDrawWidget, SLOT(setWidth(int)));

	m_pColorBtn = new QToolButton();
	QPixmap pixmap(20, 20);
	pixmap.fill(Qt::black);
	m_pColorBtn->setIcon(QIcon(pixmap));
	connect(m_pColorBtn, SIGNAL(clicked()), this, SLOT(ShowColor()));

	m_pClearBtn = new QToolButton();
	m_pClearBtn->setText(tr("Clear"));
	connect(m_pClearBtn, SIGNAL(clicked()), m_pDrawWidget, SLOT(clear()));

	pToolBar->addWidget(m_pStyleLabel);
	pToolBar->addWidget(m_pStyleComboBox);
	pToolBar->addWidget(m_pWidthLabel);
	pToolBar->addWidget(m_pWidthSpinBox);
	pToolBar->addWidget(m_pColorBtn);
	pToolBar->addWidget(m_pClearBtn);
}

void mainwindow::ShowStyle()
{
	m_pDrawWidget->setStyle(m_pStyleComboBox->itemData(m_pStyleComboBox->currentIndex(), Qt::UserRole).toInt());
}

void mainwindow::ShowColor()
{
	QColor color = QColorDialog::getColor(static_cast<int>(Qt::black));
	if (color.isValid())
	{
		m_pDrawWidget->setColor(color);
		QPixmap pixmap(20, 20);
		pixmap.fill(color);
		m_pColorBtn->setIcon(QIcon(pixmap));
	}
}
