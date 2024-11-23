#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    button = new QPushButton(this);
//    button->setText("按钮");
//    button->move(400,370);

//    connect(button,&QPushButton::clicked,this,&Widget::handleClicked);
}

Widget::~Widget()
{
    delete ui;
}

//void Widget::handleClicked()
//{
//    // button->move(350,300);

//    this->setWindowTitle("标题已被修改！");
//}


void Widget::on_pushButton_clicked()
{
    this->setWindowTitle("标题已被修改！");
}
