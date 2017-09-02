#ifndef TIMECLIENT_H
#define TIMECLIENT_H

#include <QtWidgets/QDialog>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qtcpsocket.h>
#include <qabstractsocket.h>

class TimeClient : public QDialog
{
	Q_OBJECT

public:
	TimeClient(QWidget *parent = 0);
	~TimeClient();
	public slots:
	void enabelGetBtn();
	void getTime();
	void readTime();
	void ShowError(QAbstractSocket::SocketError error);
private:
	QLabel *m_pServerNameLabel;
	QLineEdit* m_pServerNameEdit;
	QLabel *m_pPortLabel;
	QLineEdit* m_pPortEdit;
	QDateTimeEdit * m_pTimeEdit;
	QLabel * m_pStartLabel;
	QPushButton * m_pGetBtn;
	QPushButton * m_pQuitBtn;

	uint m_Time2u;
	QTcpSocket * m_pSocket;
};


#endif // TIMECLIENT_H
