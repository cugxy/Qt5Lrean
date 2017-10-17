/********************************************************************************
** Form generated from reading UI file 'myword.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWORD_H
#define UI_MYWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWordClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *MyWordClass)
    {
        if (MyWordClass->objectName().isEmpty())
            MyWordClass->setObjectName(QStringLiteral("MyWordClass"));
        MyWordClass->resize(600, 400);
        centralWidget = new QWidget(MyWordClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyWordClass->setCentralWidget(centralWidget);

        retranslateUi(MyWordClass);

        QMetaObject::connectSlotsByName(MyWordClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyWordClass)
    {
        MyWordClass->setWindowTitle(QApplication::translate("MyWordClass", "MyWord", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyWordClass: public Ui_MyWordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWORD_H
