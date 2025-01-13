#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 连接信号槽,通过槽函数更新界面
    connect(&thread, &Thread::notify, this, &Widget::ThreadHandle);
    // start 启动线程
    thread.start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ThreadHandle()
{
    // 修改界面内容
    int value = ui->lcdNumber->intValue();
    value--;
    ui->lcdNumber->display(value);
}

