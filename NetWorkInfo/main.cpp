#include "networkinfo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	
	NetWorkInfo w;
	w.show();
	return a.exec();
}
