#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    // 创建 MessageBox
    QMessageBox* box = new QMessageBox(this);
    box->setWindowTitle("对话框标题");
    box->setText("这是对话框文本");
    box->setIcon(QMessageBox::Warning);
    // box->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::Help);


    box->exec();
    box->setAttribute(Qt::WA_DeleteOnClose);
}
