/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetClass
{
public:
    QStackedWidget *managerPage;
    QWidget *page;
    QLabel *label;
    QToolBox *toolBox;
    QWidget *page_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *sellFactComBox;
    QComboBox *sellBandComBox;
    QLineEdit *sellPriceLineEidt;
    QLineEdit *sellSumLineEdit;
    QSpinBox *sellNumSpinBox;
    QLabel *label_12;
    QLabel *label_19;
    QLabel *sellLastNumLabel;
    QPushButton *sellOkBtn;
    QPushButton *sellCancelBtn;
    QWidget *page_4;
    QListWidget *dailyList;
    QWidget *page_2;

    void setupUi(QWidget *WidgetClass)
    {
        if (WidgetClass->objectName().isEmpty())
            WidgetClass->setObjectName(QStringLiteral("WidgetClass"));
        WidgetClass->resize(741, 491);
        managerPage = new QStackedWidget(WidgetClass);
        managerPage->setObjectName(QStringLiteral("managerPage"));
        managerPage->setGeometry(QRect(20, 40, 701, 411));
        managerPage->setFrameShape(QFrame::NoFrame);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 0, 621, 20));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);
        label->setFrameShape(QFrame::StyledPanel);
        label->setAlignment(Qt::AlignCenter);
        toolBox = new QToolBox(page);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(40, 40, 311, 361));
        toolBox->setFrameShape(QFrame::WinPanel);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 307, 305));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(22, 20, 36, 16));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(22, 50, 36, 16));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(22, 80, 36, 16));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 140, 36, 16));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(22, 110, 36, 16));
        sellFactComBox = new QComboBox(page_3);
        sellFactComBox->setObjectName(QStringLiteral("sellFactComBox"));
        sellFactComBox->setGeometry(QRect(66, 20, 69, 20));
        sellBandComBox = new QComboBox(page_3);
        sellBandComBox->setObjectName(QStringLiteral("sellBandComBox"));
        sellBandComBox->setGeometry(QRect(66, 50, 69, 20));
        sellPriceLineEidt = new QLineEdit(page_3);
        sellPriceLineEidt->setObjectName(QStringLiteral("sellPriceLineEidt"));
        sellPriceLineEidt->setGeometry(QRect(66, 80, 133, 20));
        sellSumLineEdit = new QLineEdit(page_3);
        sellSumLineEdit->setObjectName(QStringLiteral("sellSumLineEdit"));
        sellSumLineEdit->setGeometry(QRect(66, 140, 133, 20));
        sellNumSpinBox = new QSpinBox(page_3);
        sellNumSpinBox->setObjectName(QStringLiteral("sellNumSpinBox"));
        sellNumSpinBox->setGeometry(QRect(66, 110, 40, 20));
        label_12 = new QLabel(page_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(207, 80, 16, 16));
        label_19 = new QLabel(page_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(207, 140, 16, 16));
        sellLastNumLabel = new QLabel(page_3);
        sellLastNumLabel->setObjectName(QStringLiteral("sellLastNumLabel"));
        sellLastNumLabel->setGeometry(QRect(130, 110, 60, 16));
        sellOkBtn = new QPushButton(page_3);
        sellOkBtn->setObjectName(QStringLiteral("sellOkBtn"));
        sellOkBtn->setGeometry(QRect(30, 210, 75, 23));
        sellCancelBtn = new QPushButton(page_3);
        sellCancelBtn->setObjectName(QStringLiteral("sellCancelBtn"));
        sellCancelBtn->setGeometry(QRect(160, 210, 75, 23));
        toolBox->addItem(page_3, QString::fromUtf8("\345\207\272\345\224\256\350\275\246\350\276\206"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 98, 28));
        toolBox->addItem(page_4, QStringLiteral("Page 2"));
        dailyList = new QListWidget(page);
        dailyList->setObjectName(QStringLiteral("dailyList"));
        dailyList->setGeometry(QRect(370, 40, 291, 361));
        managerPage->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        managerPage->addWidget(page_2);

        retranslateUi(WidgetClass);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WidgetClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetClass)
    {
        WidgetClass->setWindowTitle(QApplication::translate("WidgetClass", "Car Sales Manager", Q_NULLPTR));
        label->setText(QApplication::translate("WidgetClass", "\345\223\201\347\211\214\350\275\246\347\256\241\347\220\206", Q_NULLPTR));
        label_2->setText(QApplication::translate("WidgetClass", "\345\216\202\345\256\266\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("WidgetClass", "\345\223\201\347\211\214\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("WidgetClass", "\346\212\245\344\273\267\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("WidgetClass", "\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("WidgetClass", "\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("WidgetClass", "\344\270\207", Q_NULLPTR));
        label_19->setText(QApplication::translate("WidgetClass", "\344\270\207", Q_NULLPTR));
        sellLastNumLabel->setText(QApplication::translate("WidgetClass", "\345\211\251\344\275\231\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        sellOkBtn->setText(QApplication::translate("WidgetClass", "\347\241\256\345\256\232", Q_NULLPTR));
        sellCancelBtn->setText(QApplication::translate("WidgetClass", "\345\217\226\346\266\210", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("WidgetClass", "\345\207\272\345\224\256\350\275\246\350\276\206", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("WidgetClass", "Page 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetClass: public Ui_WidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
