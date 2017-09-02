#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>

class Ui_WidgetClass;

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = 0);
	~Widget();

private:
	Ui_WidgetClass *ui;
};

#endif // WIDGET_H
