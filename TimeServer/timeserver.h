#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QTcpServer>
class dialog;

class TimeServer : public QTcpServer
{
	Q_OBJECT

public:
	TimeServer(QObject *parent = 0);
	~TimeServer();
protected:
	public slots:
	void newConnect();
private:
	dialog * m_pDlg;
};

#endif // TIMESERVER_H
