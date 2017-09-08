#pragma once
#include "qabstractitemview.h"
class PieView : public QAbstractItemView
{
	Q_OBJECT
public:
	explicit PieView();
	~PieView();
	void painEvent(QPaintEvent *);
private:

};

