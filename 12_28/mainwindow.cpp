#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>

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
    // 弹出对话框
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("对话框");
    dialog->resize(400, 300);
    dialog->show();
    dialog->setAttribute(Qt::WA_DeleteOnClose);
}
