#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QDomDocument>

class Ui_WidgetClass;

class Widget : public QMainWindow
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

	enum DataTimeType {Time, Date, DateTime};
	QString getDateTime(DataTimeType type);

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
	void createMenuBar();
private:
	Ui_WidgetClass *ui;
	QDomDocument doc;
	bool docRead();
	bool docWrite();
	void writeXML();
	void createNodes(QDomElement &data);
	void showDailyList();

};

#endif // WIDGET_H
