#include "imageprocessor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImageProcessor w;
	w.show();
	return a.exec();
}
