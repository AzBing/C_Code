#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QGridLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建一组3行2列
    QPushButton* butt1 = new QPushButton("按钮1");
    QPushButton* butt2 = new QPushButton("按钮2");
    QPushButton* butt3 = new QPushButton("按钮3");
    QPushButton* butt4 = new QPushButton("按钮4");
    QPushButton* butt5 = new QPushButton("按钮5");
    QPushButton* butt6 = new QPushButton("按钮6");

    // 放开拉伸系数
    butt1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    butt2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    butt3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    butt4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    butt5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    butt6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // 创建layout把按钮添加进去
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(butt1, 0, 0);
    layout->addWidget(butt2, 0, 1);
    layout->addWidget(butt3, 1, 0);
    layout->addWidget(butt4, 1, 1);
    layout->addWidget(butt5, 2, 0);
    layout->addWidget(butt6, 2, 1);

    this->setLayout(layout);
    // 设置拉伸系数
    layout->setRowStretch(0, 1);
    layout->setRowStretch(1, 2);
    layout->setRowStretch(2, 3);
}

Widget::~Widget()
{
    delete ui;
}

