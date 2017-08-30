#pragma once
#include <qthread.h>

class Product : public QThread
{
public:
	Product();
	void run();
};