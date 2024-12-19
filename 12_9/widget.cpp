#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建垂直的布局管理器
    QVBoxLayout* vlayout = new QVBoxLayout();
    this->setLayout(vlayout);

    // 添加两个按钮
    QPushButton* butt1 = new QPushButton("按键1");
    QPushButton* butt2 = new QPushButton("按钮2");
    vlayout->addWidget(butt1);
    vlayout->addWidget(butt2);

    // 创建水平的布局管理器
    QHBoxLayout* hlayout = new QHBoxLayout();

    // 添加按钮
    QPushButton* butt3 = new QPushButton("按钮3");
    QPushButton* butt4 = new QPushButton("按钮4");
    hlayout->addWidget(butt3);
    hlayout->addWidget(butt4);

    // 把水平布局管理器添加到垂直布局管理器内部
    vlayout->addLayout(hlayout);
}

Widget::~Widget()
{
    delete ui;
}

