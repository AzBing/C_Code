#include "dialog.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

Dialog::Dialog(QWidget* parent) : QDialog(parent)
{
    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);

    QLabel* label = new QLabel("对话框",this);
    QPushButton* button = new QPushButton("退出", this);
    layout->addWidget(label);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &Dialog::handle);
}

void Dialog::handle()
{
    this->close();
}
