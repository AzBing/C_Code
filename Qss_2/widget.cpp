#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton->setStyleSheet(("QPushButton { font-size: 50px;}"));
}

Widget::~Widget()
{
    delete ui;
}

