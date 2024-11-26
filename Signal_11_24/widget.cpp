#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(300,300);

    connect(button, &QPushButton::clicked, this, [button](){
       qDebug() << "lambda 被执行了!";
       button->move(350,270);
    });
}

Widget::~Widget()
{
    delete ui;
}

