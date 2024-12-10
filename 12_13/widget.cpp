#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox->addItem("麻辣鸡腿堡");
    ui->comboBox->addItem("芝士汉堡");
    ui->comboBox->addItem("牛肉汉堡");

    ui->comboBox_2->addItem("薯条");
    ui->comboBox_2->addItem("鸡翅");
    ui->comboBox_2->addItem("鸡块");

    ui->comboBox_3->addItem("雪碧");
    ui->comboBox_3->addItem("可乐");
    ui->comboBox_3->addItem("咖啡");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug() << ui->comboBox->currentText() << "," << ui->comboBox_2->currentText() << "," << ui->comboBox_3->currentText();
}
