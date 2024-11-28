#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QPushButton* button = new QPushButton(this);
//    button->setText("按钮");
//    button->move(340,270);

//    button->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}


//void Widget::on_pushButton_clicked()
//{
//    qDebug() << "执行槽函数";
//}

//void Widget::on_pushButton_enable_clicked()
//{
//    bool enable = ui->pushButton->isEnabled();
//    if(enable)
//        ui->pushButton->setEnabled(false);
//    else
//        ui->pushButton->setEnabled(true);
//}

void Widget::on_pushButton_up_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    qDebug() << rect;
//    rect.setY(rect.y() - 5);
//    ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x(),rect.y() - 5,rect.width(),rect.height());
}

void Widget::on_pushButton_down_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    qDebug() << rect;
//    rect.setY(rect.y() + 5);
//    ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x(),rect.y() + 5,rect.width(),rect.height());
}

void Widget::on_pushButton_left_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    qDebug() << rect;
//    rect.setX(rect.x() - 5);
//    ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x() - 5,rect.y(),rect.width(),rect.height());
}

void Widget::on_pushButton_right_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    qDebug() << rect;
//    rect.setX(rect.x() + 5);
//    ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x() + 5,rect.y(),rect.width(),rect.height());
}
