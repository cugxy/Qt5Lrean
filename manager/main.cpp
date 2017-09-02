#include "widget.h"
#include <QtWidgets/QApplication>
#include "connection.h"
int main(int argc, char *argv[])
{
	if (!createConnection())
	{
		return 0;
	}

	QApplication a(argc, argv);
	Widget w;
	w.show();
	return a.exec();
}
