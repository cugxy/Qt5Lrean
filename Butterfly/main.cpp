#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include "Butterfly.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QGraphicsScene * pScene = new QGraphicsScene();
	pScene->setSceneRect(QRectF(-200, -200, 400, 400));

	Butterfly * pButterfly = new Butterfly();
	pButterfly->setPos(-100, 0);

	pScene->addItem(pButterfly);
	QGraphicsView * pView = new QGraphicsView();
	pView->setScene(pScene);
	pView->resize(600, 600);
	pView->show();
	return a.exec();
}
