#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 先在每个标签页中添加一个Label
    QLabel* label1 = new QLabel(ui->tab);
    label1->setText("标签页1");
    label1->resize(100, 50);

    QLabel* label2 = new QLabel(ui->tab_2);
    label2->setText("标签页2");
    label2->resize(100, 50);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    int count = ui->tabWidget->count();
    QWidget* w = new QWidget();
    ui->tabWidget->addTab(w, QString("Tab ") + QString::number(count + 1));

    // 添加一个QLabel显示内容
    QLabel* label = new QLabel(w);
    label->setText(QString("标签页") + QString::number(count + 1));
    label->resize(100, 50);
    // 设置添加时被自动选中
    ui->tabWidget->setCurrentIndex(count);
}

void Widget::on_pushButton_2_clicked()
{
    // 先获取当前选中标签页的下标
    int index = ui->tabWidget->currentIndex();
    // 删除
    ui->tabWidget->removeTab(index);
}
