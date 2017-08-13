#include "mainwidget.h"
#include <QtWidgets/QApplication>
#include <qfont.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFont t("ZYSong18030", 12);
	a.setFont(t);
	MainWidget w;
	w.show(); 
	return a.exec();
}
