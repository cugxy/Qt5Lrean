#include "myword.h"
#include <QtWidgets>

MyWord::MyWord(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_pMdiArea = new QMdiArea;
	m_pMdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	m_pMdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setCentralWidget(m_pMdiArea);
	move(200, 150);
	resize(800, 500);
	setWindowTitle(tr("My Word"));
}

MyWord::~MyWord()
{

}
