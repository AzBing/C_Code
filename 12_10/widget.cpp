#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //  网格装布局
    QPushButton* butt1 = new QPushButton("按钮1");
    QPushButton* butt2 = new QPushButton("按钮2");
    QPushButton* butt3 = new QPushButton("按钮3");
    QPushButton* butt4 = new QPushButton("按钮4");

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(butt1, 0, 0);
    layout->addWidget(butt2, 1, 1);
    layout->addWidget(butt3, 2, 2);
    layout->addWidget(butt4, 3, 3);

    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

