
#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <QSemaphore>
#include <QThread>

const int knDataSize = 1000;
const int knBufferSize = 16;
int buffer[knBufferSize];

QSemaphore freeBytes(knBufferSize);
QSemaphore usedBytes(0);

class Product : public QThread
{
public:
	Product() {}
	void run()
	{
		for (int i = 0; i < knDataSize; i++)
		{
			freeBytes.acquire();
			buffer[i%knBufferSize] = (i);
			usedBytes.release();
		}
	}
};

class Consumer : public QThread
{
public:
	Consumer() {}
	void run()
	{
		for (int i = 0; i < knDataSize; i++)
		{
			usedBytes.acquire();
			fprintf(stderr, "%d\t", buffer[i%knBufferSize]);
			if (i % 16 == 0 && i != 0)
				fprintf(stderr, "\n");
			freeBytes.release();
		}
		fprintf(stderr, "\n");
	}
};


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Product pro;
	Consumer con;

	pro.start();
	con.start();

	pro.wait();
	con.wait();

	return a.exec();
}
