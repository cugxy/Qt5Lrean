#pragma once
#include <QThread>

#define MAXSIZE 1
class WorkThread : public QThread {
	Q_OBJECT

public:
	WorkThread();
	~WorkThread();
protected:
	void run();


};
