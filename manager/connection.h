#pragma once

#include <qsql.h>
#include <qdebug.h>
#include <qdom.h>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QFile>

static bool createConnection()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

	db.setDatabaseName("data.db");
	db.setUserName("cugxy");
	db.setPassword("123456");
	if (!db.open())
	{
		return false;
	}

	QSqlQuery query;
	query.exec("create table factory(id varchar primary key, name varchar)");
	query.exec("insert into factory values ('0', '请选择厂家')");
	query.exec("insert into factory values ('01', '一汽大众')");
	query.exec("insert into factory values ('02', '福特')");
	query.exec("insert into factory values ('03', '上海大众')");

	query.exec("create table brand(id varchar primary key, name varchar, factory varchar, price int, sum int, sell int, last int)");
	query.exec("insert into brand values ('01', '奥迪A6', '一汽大众', 46, 34, 19, 39)");
	query.exec("insert into brand values ('02', '捷达', '一汽大众', 34, 54, 21, 123)");
	query.exec("insert into brand values ('03', '奔驰', '一汽大众', 66, 64, 76, 23)");
	query.exec("insert into brand values ('04', '福特野马', '福特', 90, 89, 99, 897)");
	query.exec("insert into brand values ('05', '老炮', '福特', 426, 754, 72, 57)");
	query.exec("insert into brand values ('06', '史蒂夫', '福特', 54, 456, 19, 56)");
	query.exec("insert into brand values ('07', '帕萨特', '上海大众', 73, 67, 512, 123)");
	query.exec("insert into brand values ('08', '桑塔纳', '上海大众', 72, 23, 19, 451)");
	query.exec("insert into brand values ('09', '奥额为', '上海大众', 54, 165, 65, 23)");
	return true;
}

static bool createXML()
{
	QFile file("data.xml");
	if (file.exists()) return true;
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return false;
	QDomDocument doc;
	QDomProcessingInstruction instruction;
	instruction = doc.createProcessingInstruction("xml", "version = \"1.0\"encoding=\"UTF-8\"");
	doc.appendChild(instruction);
	QDomElement root = doc.createElement(QString("日销售清单"));
	doc.appendChild(root);
	QTextStream out(&file);
	doc.save(out, 4);
	file.close();
	return true;
}

