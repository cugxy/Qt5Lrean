#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	,ui(new Ui_WidgetClass())
{
	ui->setupUi(this);
}

Widget::~Widget()
{

}
