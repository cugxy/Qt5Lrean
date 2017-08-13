#include "showwidget.h"
#include <QHBoxLayout>
ShowWidget::ShowWidget(QWidget *parent)
	: QWidget(parent)
{
	m_pImageLabel = new QLabel();
	m_pImageLabel->setScaledContents(true);

	m_pText = new QTextEdit();

	QHBoxLayout * pMainLayout = new QHBoxLayout(this);
	pMainLayout->addWidget(m_pImageLabel);
	pMainLayout->addWidget(m_pText);
}

ShowWidget::~ShowWidget()
{

}
