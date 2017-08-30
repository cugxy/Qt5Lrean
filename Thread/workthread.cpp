#include "workthread.h"
#include <qdebug.h>
WorkThread::WorkThread() : QThread()
{
	
}

WorkThread::~WorkThread() 
{
	
}

void WorkThread::run()
{
	while (true)
	{
		for (int i = 0; i < 10; i++)
			qDebug() << i << i << endl;
	}
}
