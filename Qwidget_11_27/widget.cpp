#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(350,260);

    connect(button,&QPushButton::clicked,this,&Widget::hanle);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::hanle()
{
    // 针对 Widget 对象来使用geometry和framegeometry的区别
    QRect rect1 = this->geometry();
    QRect rect2 = this->frameGeometry();

    qDebug() << rect1;
    qDebug() << rect2;
}

