/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "dropedit.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    DropEdit *textEdit;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *win_top;
    QCheckBox *win_capture;
    QLabel *label_2;
    QSpinBox *font_size;
    QLabel *label;
    QSpinBox *transparent;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_highlight;
    QPushButton *pushButton_clearHighlight;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_increaseSpeed;
    QPushButton *pushButton_decreaseSpeed;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(624, 231);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new DropEdit(Widget);
        textEdit->setObjectName("textEdit");
        textEdit->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(textEdit);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        win_top = new QCheckBox(groupBox);
        win_top->setObjectName("win_top");
        win_top->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(win_top);

        win_capture = new QCheckBox(groupBox);
        win_capture->setObjectName("win_capture");
        win_capture->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(win_capture);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(50, 16777215));
        label_2->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(label_2);

        font_size = new QSpinBox(groupBox);
        font_size->setObjectName("font_size");
        font_size->setMaximumSize(QSize(40, 16777215));
        font_size->setMinimum(1);
        font_size->setMaximum(100);
        font_size->setValue(9);

        horizontalLayout->addWidget(font_size);

        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setMaximumSize(QSize(40, 16777215));
        label->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(label);

        transparent = new QSpinBox(groupBox);
        transparent->setObjectName("transparent");
        transparent->setMaximumSize(QSize(40, 16777215));
        transparent->setMinimum(10);
        transparent->setMaximum(100);
        transparent->setValue(100);

        horizontalLayout->addWidget(transparent);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setMinimumSize(QSize(0, 70));
        pushButton_highlight = new QPushButton(groupBox_3);
        pushButton_highlight->setObjectName("pushButton_highlight");
        pushButton_highlight->setGeometry(QRect(10, 20, 250, 20));
        pushButton_highlight->setMinimumSize(QSize(0, 20));
        pushButton_highlight->setMaximumSize(QSize(250, 20));
        pushButton_clearHighlight = new QPushButton(groupBox_3);
        pushButton_clearHighlight->setObjectName("pushButton_clearHighlight");
        pushButton_clearHighlight->setGeometry(QRect(290, 20, 300, 20));
        pushButton_clearHighlight->setMinimumSize(QSize(0, 20));
        pushButton_clearHighlight->setMaximumSize(QSize(300, 20));
        lineEdit_search = new QLineEdit(groupBox_3);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setGeometry(QRect(80, 50, 300, 20));
        lineEdit_search->setMinimumSize(QSize(300, 20));
        lineEdit_search->setMaximumSize(QSize(300, 20));
        pushButton_search = new QPushButton(groupBox_3);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setGeometry(QRect(20, 50, 50, 20));
        pushButton_search->setMinimumSize(QSize(0, 20));
        pushButton_search->setMaximumSize(QSize(50, 20));

        verticalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(0, 40));
        pushButton_start = new QPushButton(groupBox_2);
        pushButton_start->setObjectName("pushButton_start");
        pushButton_start->setGeometry(QRect(0, 20, 100, 21));
        pushButton_start->setMinimumSize(QSize(100, 0));
        pushButton_start->setMaximumSize(QSize(50, 50));
        pushButton_stop = new QPushButton(groupBox_2);
        pushButton_stop->setObjectName("pushButton_stop");
        pushButton_stop->setGeometry(QRect(170, 20, 100, 18));
        pushButton_stop->setMinimumSize(QSize(100, 0));
        pushButton_stop->setMaximumSize(QSize(50, 50));
        pushButton_increaseSpeed = new QPushButton(groupBox_2);
        pushButton_increaseSpeed->setObjectName("pushButton_increaseSpeed");
        pushButton_increaseSpeed->setGeometry(QRect(330, 20, 100, 18));
        pushButton_increaseSpeed->setMinimumSize(QSize(100, 0));
        pushButton_increaseSpeed->setMaximumSize(QSize(50, 50));
        pushButton_decreaseSpeed = new QPushButton(groupBox_2);
        pushButton_decreaseSpeed->setObjectName("pushButton_decreaseSpeed");
        pushButton_decreaseSpeed->setGeometry(QRect(480, 20, 100, 18));
        pushButton_decreaseSpeed->setMinimumSize(QSize(100, 0));
        pushButton_decreaseSpeed->setMaximumSize(QSize(100, 50));

        verticalLayout->addWidget(groupBox_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\345\267\245\345\205\267\346\240\217", nullptr));
        win_top->setText(QCoreApplication::translate("Widget", "\347\252\227\345\217\243\347\275\256\351\241\266", nullptr));
        win_capture->setText(QCoreApplication::translate("Widget", "\347\246\201\346\255\242\346\215\225\350\216\267", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\255\227\344\275\223\345\244\247\345\260\217:", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\351\200\217\346\230\216\345\272\246:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\351\253\230\344\272\256", nullptr));
        pushButton_highlight->setText(QCoreApplication::translate("Widget", "\351\253\230\344\272\256", nullptr));
        pushButton_clearHighlight->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\351\253\230\344\272\256", nullptr));
        pushButton_search->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\346\273\232\350\257\215\350\256\276\347\275\256", nullptr));
        pushButton_start->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\273\232\350\257\215", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\346\273\232\350\257\215", nullptr));
        pushButton_increaseSpeed->setText(QCoreApplication::translate("Widget", "\345\212\240\351\200\237", nullptr));
        pushButton_decreaseSpeed->setText(QCoreApplication::translate("Widget", "\345\207\217\351\200\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
