/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *connectDB;
    QPushButton *closeDB;
    QPushButton *createTab;
    QPushButton *insert;
    QPushButton *select;
    QPushButton *update;
    QPushButton *detele;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        connectDB = new QPushButton(Widget);
        connectDB->setObjectName(QString::fromUtf8("connectDB"));
        connectDB->setGeometry(QRect(150, 230, 111, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        connectDB->setFont(font);
        closeDB = new QPushButton(Widget);
        closeDB->setObjectName(QString::fromUtf8("closeDB"));
        closeDB->setGeometry(QRect(530, 230, 111, 41));
        closeDB->setFont(font);
        createTab = new QPushButton(Widget);
        createTab->setObjectName(QString::fromUtf8("createTab"));
        createTab->setGeometry(QRect(80, 340, 111, 41));
        createTab->setFont(font);
        insert = new QPushButton(Widget);
        insert->setObjectName(QString::fromUtf8("insert"));
        insert->setGeometry(QRect(210, 340, 111, 41));
        insert->setFont(font);
        select = new QPushButton(Widget);
        select->setObjectName(QString::fromUtf8("select"));
        select->setGeometry(QRect(340, 340, 111, 41));
        select->setFont(font);
        update = new QPushButton(Widget);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(470, 340, 111, 41));
        update->setFont(font);
        detele = new QPushButton(Widget);
        detele->setObjectName(QString::fromUtf8("detele"));
        detele->setGeometry(QRect(600, 340, 111, 41));
        detele->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        connectDB->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", nullptr));
        closeDB->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200\346\225\260\346\215\256\345\272\223", nullptr));
        createTab->setText(QCoreApplication::translate("Widget", "\345\210\233\345\273\272\350\241\250", nullptr));
        insert->setText(QCoreApplication::translate("Widget", "\346\217\222\345\205\245", nullptr));
        select->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242", nullptr));
        update->setText(QCoreApplication::translate("Widget", "\346\233\264\346\226\260", nullptr));
        detele->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
