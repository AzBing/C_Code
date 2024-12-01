#include "widget.h"
#include "ui_widget.h"
#include <QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QIcon icon("d:/qx.jpg");
    QIcon icon(":/qx.jpg");
    this->setWindowIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}

