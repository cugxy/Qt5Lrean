#include "dialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	dialog w;
	w.show();
	return a.exec();
}
