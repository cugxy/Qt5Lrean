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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWordClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyWordClass)
    {
        if (MyWordClass->objectName().isEmpty())
            MyWordClass->setObjectName(QStringLiteral("MyWordClass"));
        MyWordClass->resize(600, 400);
        menuBar = new QMenuBar(MyWordClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyWordClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyWordClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyWordClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyWordClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyWordClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyWordClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyWordClass->setStatusBar(statusBar);

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
