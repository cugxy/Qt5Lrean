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

bool MyChild::loadFile(const QString &strFileName)
{
	if (!strFileName.isEmpty())
	{
		if (QFile::exists(strFileName))
		{
			QFile file(strFileName);
			if (file.open(QFile::ReadOnly))
			{
				QByteArray data = file.readAll();
				QTextCodec * pCodec = Qt::codecForHtml(data);
				QString str = pCodec->toUnicode(data);
				if (Qt::mightBeRichText(str))
				{
					this->setHtml(str);
				}
				else
				{
					str = QString::fromLocal8Bit(data);
					this->setPlainText(str);
				}
				setCurrentFile(strFileName);
				connect(document(), SIGNAL(contentsChanged()), this, SLOT(slotDocumentWasModefied()));
				return true;
			}
		}
	}
	return false;
}

QString MyChild::userFriendlyCurrentFile()
{
	return strippedName(m_strCurrentFile);
}

QString MyChild::currentFile()
{
	return QString();
}

void MyChild::setCurrentFile(const QString & strFileName)
{
	m_strCurrentFile = QFileInfo(strFileName).canonicalFilePath();
	m_bIsUntitled = false;
	document()->setModified(false);
	setWindowModified(false);
	setWindowTitle(userFriendlyCurrentFile() + "[*]");
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
	setWindowModified(document()->isModified());
}
