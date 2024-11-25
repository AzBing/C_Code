#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    this->setWindowTitle("修改窗口标题");
    qDebug() << "click1";
}

void Widget::handleClick2()
{
    this->setWindowTitle("修改窗口标题2");
    qDebug() << "click2";
}


void Widget::on_pushButton_2_clicked()
{
    // 先断开原来的信号槽
    disconnect(ui->pushButton,&QPushButton::clicked,this,&Widget::handleClick);
    // 重新绑定信号槽
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::handleClick2);
}
