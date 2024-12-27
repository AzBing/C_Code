#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建菜单栏
    QMenuBar* menubar = this->menuBar();
    this->setMenuBar(menubar);

    // 创建菜单项
    QMenu* menu = new QMenu("文件");
    menubar->addMenu(menu);

    // 工具栏需要手动创建
    QToolBar* toolbar = new QToolBar();
    this->addToolBar(toolbar);

    QAction* action1 = new QAction("保存");
    QAction* action2 = new QAction("打开");
    action1->setToolTip("点击这里保存文件");
    action1->setIcon(QIcon(":/save.png"));
    action2->setIcon(QIcon(":/open.png"));

    // 把菜单项添加到菜单中
    menu->addAction(action1);
    menu->addAction(action2);

    // 把菜单项添加到工具栏中
    toolbar->addAction(action1);
    toolbar->addAction(action2);

    connect(action1, &QAction::triggered, this, &MainWindow::handle1);
    connect(action2, &QAction::triggered, this, &MainWindow::handle2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle1()
{
    qDebug() << "handle1";
}

void MainWindow::handle2()
{
    qDebug() << "handle2";
}
