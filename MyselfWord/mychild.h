#ifndef MYCHILD_H
#define MYCHILD_H

#include <QTextEdit>

class MyChild : public QTextEdit
{
	Q_OBJECT

public:
	MyChild(QWidget *parent = 0);
	~MyChild();
	void newFile();
	QString userFriendlyCurrentFile();
	QString currentFile();
protected:
	void closeEvent(QCloseEvent *event);
private slots:
	void slotDocumentWasModefied();
private:
	QString strippedName(const QString &fullFileName);
	QString m_strCurrentFile;
	bool m_bIsUntitled;
	
};

#endif // MYCHILD_H
