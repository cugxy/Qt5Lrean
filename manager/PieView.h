#pragma once
#include "qabstractitemview.h"
#include <QItemSelectionModel>
#include <qregion.h>

class PieView : public QAbstractItemView
{
	Q_OBJECT
public:
	explicit PieView();
	~PieView();
	void painEvent(QPaintEvent *);

	void setSelectionModel(QItemSelectionModel * pSelection);
	QRegion itemRegion(QModelIndex index);

	QRect visulRect(const QModelIndex &index)const;
	void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible);
	QModelIndex indexAt(const QPoint &point)const;
	QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
	int horizontalOffset()const;
	int verticalOffset()const;
	bool isIndexHidden(const QRect &rect, QItemSelectionModel::SelectionFlags command);
	QRegion visualRegionForSelection(const QItemSelection &selection)const;
private:
	QItemSelectionModel * m_pSelection;
	QList<QRegion> m_RegList;
};

