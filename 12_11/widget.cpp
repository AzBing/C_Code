#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* butt1 = new QPushButton("按钮1");
    QPushButton* butt2 = new QPushButton("按钮2");
    QPushButton* butt3 = new QPushButton("按钮3");
    QPushButton* butt4 = new QPushButton("按钮4");
    QPushButton* butt5 = new QPushButton("按钮5");
    QPushButton* butt6 = new QPushButton("按钮6");

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(butt1, 0, 0);
    layout->addWidget(butt2, 0, 1);
    layout->addWidget(butt3, 0, 2);
    layout->addWidget(butt4, 1, 0);
    layout->addWidget(butt5, 1, 1);
    layout->addWidget(butt6, 1, 2);
    this->setLayout(layout);

    // 设置水平拉伸系数
    layout->setColumnStretch(0, 2);
    layout->setColumnStretch(1, 3);
    layout->setColumnStretch(2, 4);
}

Widget::~Widget()
{
    delete ui;
}

