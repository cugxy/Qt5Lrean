#include "geometry.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Geometry w;
	w.show();
	return a.exec();
}
