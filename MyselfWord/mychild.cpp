#include "mychild.h"
#include <QtWidgets>

MyChild::MyChild(QWidget *parent)
	: QTextEdit(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	m_bIsUntitled = true;
}

MyChild::~MyChild()
{

}

void MyChild::newFile()
{
	static int nSequenceNumber = 1;

	m_bIsUntitled = true;
	m_strCurrentFile = tr("document %1").arg(nSequenceNumber++);

	setWindowTitle(m_strCurrentFile + "[*]" + tr(" - Myself word"));

	//connect(document(), SIGNAL(), this, SLOT(slotDocumentWasModefied()));
}

QString MyChild::userFriendlyCurrentFile()
{
	return strippedName(m_strCurrentFile);
}

QString MyChild::currentFile()
{
	return QString();
}

void MyChild::closeEvent(QCloseEvent * event)
{
	event->accept();
}

QString MyChild::strippedName(const QString & fullFileName)
{
	return QFileInfo(fullFileName).fileName();
}

void MyChild::slotDocumentWasModefied()
{
	//setWindowModefied(document()->is)
}
