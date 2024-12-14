#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

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


void Widget::on_dial_valueChanged(int value)
{
    // 通过旋钮调节窗口不透明度
    qDebug() << value;
    this->setWindowOpacity((double)value / 100);

}
