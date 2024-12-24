#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建菜单栏
    QMenuBar* bar = new QMenuBar();
    this->setMenuBar(bar);

    // 创建菜单
    QMenu* menu1 = new QMenu("文件 (&F)"); // &F 快捷键
    QMenu* menu2 = new QMenu("编辑 (&E)");
    QMenu* menu3 = new QMenu("视图 (&V)");
    QMenu* menu4 = new QMenu("关于 (&A)");
    bar->addMenu(menu1);
    bar->addMenu(menu2);
    bar->addMenu(menu3);
    bar->addMenu(menu4);

    // 创建菜单项
    QAction* action1 = new QAction("菜单项1");
    QAction* action2 = new QAction("菜单项2");
    QAction* action3 = new QAction("菜单项3");
    QAction* action4 = new QAction("菜单项4");
    menu1->addAction(action1);
    menu2->addAction(action2);
    menu3->addAction(action3);
    menu4->addAction(action4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

