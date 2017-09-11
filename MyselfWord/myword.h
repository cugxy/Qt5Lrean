#ifndef MYWORD_H
#define MYWORD_H

#include <QtWidgets/QMainWindow>
#include "ui_myword.h"

class MyWord : public QMainWindow
{
	Q_OBJECT

public:
	MyWord(QWidget *parent = 0);
	~MyWord();

private:
	Ui::MyWordClass ui;
};

#endif // MYWORD_H
