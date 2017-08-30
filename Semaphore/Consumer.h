#pragma once
#include "qthread.h"

class Consumer : public QThread
{
public:
	Consumer();
	void run();
};