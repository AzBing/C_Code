#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 建立连接并不会立即处理handle自定义信号的处理
    // connect(this,&Widget::mySignal,this,&Widget::handleMySignal);

    // 发送信号的操作，也可以在任意合适的代码中去调用
    // emit mySignal();



}

Widget::~Widget()
{
    delete ui;
}

//void Widget::handleMySignal(const QString& text)
//{
//    this->setWindowTitle(text);
//}

//void Widget::on_pushButton_clicked()
//{
//    // 发送出自定义的信号
//    // 点击按钮也可以发送自定义信号
//    emit mySignal("自定义信号标题1");
//}

//void Widget::on_pushButton_2_clicked()
//{
//    emit mySignal("自定义信号标题2");
//}

void Widget::mySlot1()
{
    qDebug() << "muSlot1";
}

void Widget::mySlot2()
{
    qDebug() << "muSlot2";
}

void Widget::mySlot3()
{
    qDebug() << "muSlot3";
}

