#include "mylabel.h"
#include <iostream>
#include <QtDebug>

Mylabel::Mylabel(QWidget* parent) : QLabel(parent)
{

}

Mylabel::~Mylabel()
{
    // std::cout << "Mylabel 被销毁！" << std::endl;
    qDebug() << "Mylabel 被销毁了！";
}
