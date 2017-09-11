#include "PieView.h"
#include <qpainter.h>
#include <QModelIndex>
#include <QColor>

PieView::PieView()
{

}


PieView::~PieView()
{
}

void PieView::painEvent(QPaintEvent *)
{
	QPainter painter(viewport());
	painter.setPen(Qt::black);
	int nX0 = 40;
	int nY0 = 250;
	painter.drawLine(nX0, nY0, 40, 30);
	painter.drawLine(38, 32, 40, 30);
	painter.drawLine(40, 30, 40, 30);
	painter.drawText(40, 30, tr("销售数量"));
	for (int i = 1; i < 5; i++)
	{
		painter.drawLine(-1, -i*50, 1, -i * 50);
		painter.drawText(-20, -i * 50, tr("%1").arg(i*5));
	}
	painter.drawLine(nX0, nY0, 540, 250);
	painter.drawLine(538, 248, 540, 250);
	painter.drawLine(540, 250, 538, 252);
	painter.drawText(545, 250, tr("品牌"));

	int pos = nX0 * 20;
	int row;
	for (row = 0; row < model()->rowCount(rootIndex()); row++)
	{
		QModelIndex index = model()->index(row, 0, rootIndex());
		QString dep = model()->data(index).toString();
		painter.drawText(pos, nY0 + 20, dep);
		pos += 50;
	}
	int posN = nX0 + 20;
	for (row = 0; row < model()->rowCount(rootIndex()); row++)
	{
		QModelIndex index = model()->index(row,1, rootIndex());
		int sell = model()->data(index).toDouble();

		int width = 10;
		QModelIndex colorIndex = model()->index(row, 0, rootIndex());
		QColor color = QColor(model()->data(colorIndex, Qt::DecorationRole).toString());
		if (m_pSelection->isSelected(index))
			painter.setBrush(QBrush(color, Qt::Dense3Pattern));
		else
			painter.setBrush(QBrush(color));

		painter.drawRect(QRect(posN, nY0 - sell * 10, width, sell * 10));
		QRegion regionM(posN, nY0 - sell * 10, width, sell * 10);
		m_RegList << regionM;
		posN += 50;
	}
}

void PieView::setSelectionModel(QItemSelectionModel * pSelection)
{
	m_pSelection = pSelection;
}

QRegion PieView::itemRegion(QModelIndex index)
{
	QRegion region;
	if (index.column() == 1)
	{
		region = m_RegList[index.row()];
	}
	return region;
}

QRect PieView::visulRect(const QModelIndex & index) const
{
	return QRect();
}

void PieView::scrollTo(const QModelIndex & index, ScrollHint hint)
{
}
QModelIndex PieView::indexAt(const QPoint & point) const
{
	QPoint newPoint(point.x(), point.y());
	QRegion region;
	foreach(region, m_RegList)
	{
		if (region.contains(newPoint))
		{
			int row = m_RegList.indexOf(region);
			QModelIndex index = model()->index(row, 1, rootIndex());
			return index;
		}
	}
	return QModelIndex();
}

QModelIndex PieView::moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{
	return QModelIndex();
}

int PieView::horizontalOffset() const
{
	return 0;
}

int PieView::verticalOffset() const
{
	return 0;
}

bool PieView::isIndexHidden(const QRect & rect, QItemSelectionModel::SelectionFlags command)
{
	return false;
}

QRegion PieView::visualRegionForSelection(const QItemSelection & selection) const
{
	return QRegion();
}
