#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QColor col = QColorDialog::getColor(QColor(0, 255, 0), this, "选择颜色");
    qDebug() << col;

    char style[1024] = {0};
    sprintf(style, "background-color: rgd(%d, %d, %d);", col.red(), col.green(), col.blue());
    this->setStyleSheet(style);
}
