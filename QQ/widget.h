#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include "ui_widget.h"

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = 0);
	~Widget();

private:
	Ui::WidgetClass ui;
};

#endif // WIDGET_H
