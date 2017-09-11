#include "myword.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyWord w;
	w.show();
	return a.exec();
}
