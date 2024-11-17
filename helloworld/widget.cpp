#include "widget.h"
#include "ui_widget.h"
#include "mylabel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Mylabel* label = new Mylabel(this);
    label->setText("Hello World");
}

Widget::~Widget()
{
    delete ui;
}

