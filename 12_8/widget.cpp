#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建三个按钮，使用垂直布局管理器
    QPushButton* but1 = new QPushButton("按钮1");
    QPushButton* but2 = new QPushButton("按钮2");
    QPushButton* but3 = new QPushButton("按钮3");
    // 创建布局管理器
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(but1);
    layout->addWidget(but2);
    layout->addWidget(but3);
    // 把布局管理器添加到Widget窗口中
    this->setLayout(layout);
    // 按钮的尺寸会随着窗口的改变而自动变化
}

Widget::~Widget()
{
    delete ui;
}

