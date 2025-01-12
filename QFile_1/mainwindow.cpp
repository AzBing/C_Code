#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("记事本");

    // 获取菜单栏
    QMenuBar* menuBar = this->menuBar();

    // 添加菜单
    QMenu* menu = new QMenu("文件");
    menuBar->addMenu(menu);

    // 添加菜单项
    QAction* action1 = new QAction("打开");
    QAction* action2 = new QAction("保存");
    menu->addAction(action1);
    menu->addAction(action2);

    // 指定一个输入框
    edit = new QPlainTextEdit();
    QFont font;
    font.setPixelSize(25);
    edit->setFont(font);
    this->setCentralWidget(edit);

    // 链接Action信号槽
    connect(action1, &QAction::triggered, this , &MainWindow::handleAction1);
    connect(action2, &QAction::triggered, this , &MainWindow::handleAction2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleAction1()
{
    // 点击 先弹出 “打开文件”
    QString path = QFileDialog::getOpenFileName(this);
    // 文件名显示到状态栏中
    QStatusBar* statusBar = this->statusBar();
    statusBar->showMessage(path);
    // 根据用户选择的方式，构造一个QFile对象，只读的方式打开文件
    QFile file(path);
    bool ret = file.open(QFile::ReadOnly);
    if(!ret)
    {
        statusBar->showMessage(path + " 文件打开失败! ");
        return;
    }
    // 读取文件
    QString text = file.readAll();
    // 关闭文件
    file.close();
    // 读取到的文件内容设置到输入框中
    edit->setPlainText(text);
}

void MainWindow::handleAction2()
{
    // 点击之后先弹出“保存文件”
    QString path = QFileDialog::getSaveFileName(this);
    // 在状态栏中显示文件名
    QStatusBar* statusBar = this->statusBar();
    statusBar->showMessage(path);
    // 根据用户选择的方式，构造一个QFile对象，只写的方式打开文件
    QFile file(path);
    bool ret = file.open(QFile::WriteOnly);
    if(!ret)
    {
        statusBar->showMessage(path + " 文件打开失败! ");
        return;
    }
    // 写文件
    const QString& text = edit->toPlainText();
    file.write(text.toUtf8());
    // 关闭文件
    file.close();
}

