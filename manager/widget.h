#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QMainWindow>
#include <QMenuBar>

class Ui_WidgetClass;

class Widget : public QMainWindow
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

	QMenu * m_pManageMenu;
	QMenu * m_pPasswordMenu;

	QAction * m_pManageAct;
	QAction * m_pChartAct;
	QAction * m_pQuitAct;
	private slots:
	void slotOnManageMenuClicked();
	void slotOnChartMenuClicked();
	void slotOnQuitMenuClicked();
	void slotSellFactComBoxCurrentIndexChanged(const QString &);
	void slotSellBrandComBoxCurrentIndexChanged(const QString &);
	void slotSellNumSpinBoxValueChanged(int);
	void slotSellOkClicked();
	void slotSellCancelClicked();
private:
	Ui_WidgetClass *ui;
	void createMenuBar();
};

#endif // WIDGET_H
