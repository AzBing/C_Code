#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QDateTime timeOld = ui->dateTimeEdit->dateTime();
    QDateTime timeNew = ui->dateTimeEdit_2->dateTime();
    qDebug() << timeOld << timeNew;
    // 计算日期差值
    // int days = timeOld.daysTo(timeNew);
    int seconds = timeOld.secsTo(timeNew);
    // 把秒数转换成小时
    int days = (seconds / 3600) / 24;
    int hours = (seconds / 3600) % 24;
    ui->label->setText(QString("你在这个世界上生活了") + QString::number(days) + QString("天零") + QString::number(hours) + QString("小时"));

    qDebug() << days;
}
