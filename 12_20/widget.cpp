#include "widget.h"
#include "ui_widget.h"

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置成3行2列的表单
    QFormLayout* layout = new QFormLayout();
    this->setLayout(layout);

    // 创建三个label作为第一列
    QLabel* label1 = new QLabel("姓名");
    QLabel* label2 = new QLabel("年龄");
    QLabel* label3 = new QLabel("电话");

    // 创建三个输入框作为第二列
    QLineEdit* edit1 = new QLineEdit();
    QLineEdit* edit2 = new QLineEdit();
    QLineEdit* edit3 = new QLineEdit();

    layout->addRow(label1, edit1);
    layout->addRow(label2, edit2);
    layout->addRow(label3, edit3);

    QPushButton* butt = new QPushButton("提交");
    layout->addRow(nullptr, butt);
}

Widget::~Widget()
{
    delete ui;
}

