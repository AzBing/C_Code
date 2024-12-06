#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 往QListWidget里添加字符串
    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Java");
    ui->listWidget->addItem("Python");

//    ui->listWidget->addItem(new QListWidgetItem("C++"));
//    ui->listWidget->addItem(new QListWidgetItem("Java"));
//    ui->listWidget->addItem(new QListWidgetItem("Python"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_Insert_clicked()
{
    // 先获取输入框中内容
    const QString& test = ui->lineEdit->text();
    // 添加到Qlistwidget中
    ui->listWidget->addItem(test);
}

void Widget::on_pushButton_Delete_clicked()
{
    // 先获取被选中的元素
    int row = ui->listWidget->currentRow();
    if(row < 0)
        return;
    ui->listWidget->takeItem(row);
}

void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    // 通过这个槽函数来感知到变化
    if(current != nullptr)
        qDebug() << "当前选中的元素：" << current->text();
    if(previous != nullptr)
        qDebug() << "上次选中的元素：" << previous->text();
}
