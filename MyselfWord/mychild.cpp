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

bool MyChild::save()
{
	if (m_bIsUntitled)
		return saveAs();
	else
		return saveFile(m_strCurrentFile);
}

bool MyChild::saveAs()
{
	QString strFileName = QFileDialog::getOpenFileName(this, tr("Open"), QString(), tr("Html(*.html|*.htm); All(*.*)"));
	if (strFileName.isEmpty())
		return false;
	return saveFile(m_strCurrentFile);
}

bool MyChild::saveFile(QString strFileName)
{
	if (!(strFileName.endsWith(".htm", Qt::CaseInsensitive) || (strFileName.endsWith(".html", Qt::CaseInsensitive))))
	{
		strFileName.append(".html");
	}
	QTextDocumentWriter writer(strFileName);
	bool bSuccess = writer.write(this->document());
	if (bSuccess)
		setCurrentFile(strFileName);
	return bSuccess;
}

QString MyChild::userFriendlyCurrentFile()
{
	return strippedName(m_strCurrentFile);
}

QString MyChild::currentFile()
{
	return QString();
}

void MyChild::mergeFormatOnWordOrSelection(const QTextCharFormat & format)
{
	QTextCursor cursor = this->textCursor();	
	if (!cursor.hasSelection())
		cursor.select(QTextCursor::WordUnderCursor);
	cursor.mergeCharFormat(format);
	this->mergeCurrentCharFormat(format);
}

void MyChild::setCurrentFile(const QString & strFileName)
{
	m_strCurrentFile = QFileInfo(strFileName).canonicalFilePath();
	m_bIsUntitled = false;
	document()->setModified(false);
	setWindowModified(false);
	setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

bool MyChild::maybeSave()
{
	if (!document()->isModified())
		return true;
	QMessageBox::StandardButton ret;
	ret = QMessageBox::warning(this, tr("My Qt Word"), tr("file %1 is modified, would you like to save?").arg(userFriendlyCurrentFile()), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
	if (QMessageBox::Save == ret)
		return save();
	else if (QMessageBox::Cancel == ret)
		return false;
	return true;
}

void MyChild::closeEvent(QCloseEvent * event)
{
	if (maybeSave())
		event->accept();
	else
		event->ignore();
}

QString MyChild::strippedName(const QString & fullFileName)
{
	return QFileInfo(fullFileName).fileName();
}

void MyChild::slotDocumentWasModefied()
{
	setWindowModified(document()->isModified());
}
