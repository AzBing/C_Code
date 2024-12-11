#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>
#include <fstream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 读文件，把文件内容的每一行读出来，作为ComboBox的选项
    std::ifstream file("C:/Users/DELL/Desktop/code/course.txt");
    if(!file.is_open())
    {
        qDebug() << "file open error";
        return;
    }
    // 按行读取文本内容 使用getline函数完成
    std::string line;
    while(std::getline(file, line))
    {
        // 把获取到的每一行内容添加到下拉框中
        ui->comboBox->addItem(QString::fromStdString(line));
    }
    file.close();
}

Widget::~Widget()
{
    delete ui;
}

