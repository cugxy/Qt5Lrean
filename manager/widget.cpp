#include "widget.h"
#include "ui_widget.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <qsplitter.h>
#include <qmessagebox.h>
#include <qdatetime.h>
#include <QFile>
#include <QTextStream>

Widget::Widget(QWidget *parent)
	: QMainWindow(parent)
	,ui(new Ui_WidgetClass())
{
	ui->setupUi(this);
	setFixedSize(750, 500);
	createMenuBar();

	ui->managerPage->setCurrentIndex(0);
	QSqlQueryModel * pFactoryModel = new QSqlQueryModel(this);
	pFactoryModel->setQuery("SELECT name FROM factory");
	ui->sellFactComBox->setModel(pFactoryModel);
	
	QSplitter * pSplitter = new QSplitter(ui->managerPage);
	pSplitter->resize(700, 360);
	pSplitter->move(0, 50);
	pSplitter->addWidget(ui->toolBox);
	pSplitter->addWidget(ui->dailyList);
	pSplitter->setStretchFactor(0, 1);
	pSplitter->setStretchFactor(1, 1);

	connect(ui->sellOkBtn, SIGNAL(clicked()), this, SLOT(slotSellOkClicked()));
	connect(ui->sellCancelBtn, SIGNAL(clicked()), this, SLOT(slotSellCancelClicked()));

	connect(ui->sellFactComBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotSellFactComBoxCurrentIndexChanged(QString)));
	connect(ui->sellBandComBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotSellBrandComBoxCurrentIndexChanged(QString)));
	connect(ui->sellNumSpinBox, SIGNAL(valueChanged(int)), this, SLOT(slotSellNumSpinBoxValueChanged(int)));

	slotSellCancelClicked();
	showDailyList();
}

Widget::~Widget()
{

}

QString Widget::getDateTime(DataTimeType type)
{
	QDateTime datetime = QDateTime::currentDateTime();
	QString date = datetime.toString("yyyy-MM-dd");
	QString time = datetime.toString("hh:mm:ss");
	QString dateandtime = datetime.toString("yyyy-MM-dd dddd hh:mm");
	switch (type)
	{
	case Widget::Time:
		return time;
		break;
	case Widget::Date:
		return date;
		break;
	case Widget::DateTime:
		return dateandtime;
		break;
	default:
		return QString();
		break;
	}
}

void Widget::slotOnManageMenuClicked()
{
	ui->managerPage->setCurrentIndex(0);
}

void Widget::slotOnChartMenuClicked()
{
	ui->managerPage->setCurrentIndex(1);
}

void Widget::slotOnQuitMenuClicked()
{
	this->close();
}

void Widget::slotSellFactComBoxCurrentIndexChanged(const QString &strArg)
{
	if (strArg == "请选择厂家")
		slotSellCancelClicked();
	else
	{
		ui->sellBandComBox->setEnabled(true);
		QSqlQueryModel * pModel = new QSqlQueryModel(this);
		pModel->setQuery(QString("SELECT name FROM brand WHERE factory = '%1' ").arg(strArg));
		ui->sellBandComBox->setModel(pModel);
		ui->sellCancelBtn->setEnabled(true);
	}
}

void Widget::slotSellBrandComBoxCurrentIndexChanged(const QString &strArg)
{
	ui->sellNumSpinBox->setValue(0);
	ui->sellNumSpinBox->setEnabled(false);
	ui->sellSumLineEdit->clear();
	ui->sellSumLineEdit->setEnabled(false);
	ui->sellOkBtn->setEnabled(false);

	QSqlQuery query;
	query.exec(QString("SELECT price FROM brand WHERE name = '%1' and factory = '%2' ").arg(strArg).arg(ui->sellFactComBox->currentText()));
	query.next();
	ui->sellPriceLineEidt->setEnabled(true);
	ui->sellPriceLineEidt->setReadOnly(true);
	ui->sellPriceLineEidt->setText(query.value(0).toString());

	query.exec(QString("SELECT last FROM brand WHERE name = '%1' and factory = '%2' ").arg(strArg).arg(ui->sellFactComBox->currentText()));
	query.next();
	int num = query.value(0).toInt();
	if (0 == num)
	{
		QMessageBox::information(this, tr("提示"), tr("该品牌汽车已售完"), QMessageBox::Ok);
	}
	else
	{
		ui->sellNumSpinBox->setEnabled(true);
		ui->sellNumSpinBox->setMaximum(num);
		ui->sellLastNumLabel->setText(tr("剩余数量：%1").arg(num));
		ui->sellLastNumLabel->setVisible(true);
	}
}

void Widget::slotSellNumSpinBoxValueChanged(int nArg)
{
	if (0 == nArg)
	{
		ui->sellSumLineEdit->clear();
		ui->sellSumLineEdit->setEnabled(false);
		ui->sellOkBtn->setEnabled(false);
	 }
	else
	{
		ui->sellSumLineEdit->setEnabled(true);
		ui->sellSumLineEdit->setReadOnly(true);
		qreal sum = nArg * (ui->sellPriceLineEidt->text().toInt());
		ui->sellSumLineEdit->setText(QString::number(sum));
		ui->sellOkBtn->setEnabled(true);
	}
}

void Widget::slotSellOkClicked()
{
	QString strFactory = ui->sellFactComBox->currentText();
	QString strName = ui->sellBandComBox->currentText();
	int nValue = ui->sellNumSpinBox->value();
	int nLast = ui->sellNumSpinBox->maximum() - nValue;

	QSqlQuery query;
	query.exec(QString("SELECT sell FROM brand WHERE name = '%1' AND factory = '%2' ").arg(strName.arg(strFactory)));
	query.next();
	int nSell = query.value(0).toInt() + nValue;

	QSqlDatabase::database().transaction();
	bool nRTN = query.exec(QString("UPDATE brand SET sell = %1, last = %2 WHERE name = '%3' AND factory = '%4' ").arg(nSell).arg(nLast).arg(strName).arg(strFactory));
	if (nRTN)
	{
		QSqlDatabase::database().commit();
		QMessageBox::information(this, tr("提示"), tr("购车成功"), QMessageBox::Ok);
		writeXML();
		showDailyList();
	}
	else
	{
		QSqlDatabase::database().rollback();
	}
}

void Widget::slotSellCancelClicked()
{
	ui->sellFactComBox->setCurrentIndex(0);
	ui->sellBandComBox->clear();
}

void Widget::createMenuBar()
{
	m_pManageAct = new QAction(tr("品牌车管理"), this);
	m_pChartAct = new QAction(tr("销售统计"), this);
	m_pQuitAct = new QAction(tr("退出"), this);

	m_pManageAct->setShortcut(tr("Crtl+M"));
	m_pChartAct->setShortcut(tr("Crtl+C"));
	m_pQuitAct->setShortcut(tr("Crtl+Q"));

	m_pManageMenu = menuBar()->addMenu(tr("销售管理"));
	m_pManageMenu->addAction(m_pManageAct);
	m_pManageMenu->addAction(m_pChartAct);
	m_pManageMenu->addSeparator();
	m_pManageMenu->addAction(m_pQuitAct);

	m_pPasswordMenu = menuBar()->addMenu(tr("修改密码"));

	connect(m_pManageAct, SIGNAL(triggered()), this, SLOT(slotOnManageMenuClicked()));
	connect(m_pChartAct, SIGNAL(triggered()), this, SLOT(slotOnChartMenuClicked()));
	connect(m_pQuitAct, SIGNAL(triggered()), this, SLOT(slotOnQuitMenuClicked()));
}

bool Widget::docRead()
{
	QFile file("data.xml");
	if (!file.open(QIODevice::ReadOnly)) return false;
	if (!m_doc.setContent(&file))
	{
		file.close();
		return false;
	}
	file.close();
	return true;
}

bool Widget::docWrite()
{
	QFile file("data.xml");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))return false;
	QTextStream out(&file);
	m_doc.save(out, 4);
	file.close();
	return true;
}

void Widget::writeXML()
{
	if (docRead())
	{
		QString currentData = getDateTime(Date);
		QDomElement root = m_doc.documentElement();
		if (!root.hasChildNodes())
		{
			QDomElement date = m_doc.createElement(QString("日期"));
			QDomAttr curDate = m_doc.createAttribute("date");
			curDate.setValue(currentData);
			date.setAttributeNode(curDate);
			root.appendChild(date);
			createNodes(date);
		}
		else
		{
			QDomElement date = root.lastChild().toElement();
			if (date.attribute("date") == currentData)
				createNodes(date);
			else
			{
				QDomElement date = m_doc.createElement(QString("日期"));
				QDomAttr curDate = m_doc.createAttribute("date");
				curDate.setValue(currentData);
				date.setAttributeNode(curDate);
				root.appendChild(date);
				createNodes(date);
			}
		}
		docWrite();
	}
}

void Widget::createNodes(QDomElement & data)
{
	QDomElement time = m_doc.createElement(QString("时间"));
	QDomAttr curtTme = m_doc.createAttribute("time");
	curtTme.setValue(getDateTime(Time));
	time.setAttributeNode(curtTme);
	data.appendChild(time);

	QDomElement factory = m_doc.createElement(QString("厂家"));
	QDomElement brand = m_doc.createElement(QString("品牌"));
	QDomElement price = m_doc.createElement(QString("报价"));
	QDomElement num = m_doc.createElement(QString("数量"));
	QDomElement sum = m_doc.createElement(QString("金额"));
	QDomText text;
	text = m_doc.createTextNode(QString("%1").arg(ui->sellFactComBox->currentText()));
	factory.appendChild(text);
	text = m_doc.createTextNode(QString("%1").arg(ui->sellBandComBox->currentText()));
	brand.appendChild(text);
	text = m_doc.createTextNode(QString("%1").arg(ui->sellPriceLineEidt->text()));
	price.appendChild(text);
	text = m_doc.createTextNode(QString("%1").arg(ui->sellNumSpinBox->value()));
	num.appendChild(text);
	text = m_doc.createTextNode(QString("%1").arg(ui->sellSumLineEdit->text()));
	sum.appendChild(text);

	time.appendChild(factory);
	time.appendChild(brand);
	time.appendChild(price);
	time.appendChild(num);
	time.appendChild(sum);
}

void Widget::showDailyList()
{
	ui->dailyList->clear();
	if (docRead())
	{
		QDomElement root = m_doc.documentElement();
		QString strTitle = root.tagName();
		QListWidgetItem * pTitleItem = new QListWidgetItem;
		pTitleItem->setText(QString("==========%1==========").arg(strTitle));
		pTitleItem->setTextAlignment(Qt::AlignCenter);
		ui->dailyList->addItem(pTitleItem);
		if (root.hasChildNodes())
		{
			QString strCurDate = getDateTime(Date);
			QDomElement dateElement = root.lastChild().toElement();
			QString strDate = dateElement.attribute("date");
			if (strDate == strCurDate)
			{
				ui->dailyList->addItem("");
				ui->dailyList->addItem(QString("日期%1").arg(strDate));
				ui->dailyList->addItem("");
				QDomNodeList childrens = dateElement.childNodes();
				for (int i = 0; i < childrens.count(); i++)
				{
					QDomNode node = childrens.at(i);
					QString strTime = node.toElement().attribute("time");
					QDomNodeList list = node.childNodes();
					QString strFactory = list.at(0).toElement().text();
					QString strBrand = list.at(1).toElement().text();
					QString strPrice = list.at(2).toElement().text();
					QString strNum = list.at(3).toElement().text();
					QString strSum = list.at(4).toElement().text();
					QListWidgetItem * pTempItem = new QListWidgetItem;
					pTempItem->setText(QString("======================").arg(strTitle));
					pTempItem->setTextAlignment(Qt::AlignCenter);
					ui->dailyList->addItem(pTempItem);
				}
			}
		}
	}
}
