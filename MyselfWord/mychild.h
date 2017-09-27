#ifndef MYCHILD_H
#define MYCHILD_H

#include <QLineEdit>

class MyChild : public QLineEdit
{
	Q_OBJECT

public:
	MyChild(QWidget *parent);
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
