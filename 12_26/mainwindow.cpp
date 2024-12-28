#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置工具栏状态
    QToolBar* toolbar1 = new QToolBar();
    QToolBar* toolbar2 = new QToolBar();

    this->addToolBar(toolbar1);
    this->addToolBar(Qt::LeftToolBarArea, toolbar2);

    // 只允许在左侧或右侧停靠
    // toolbar2->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    // 设置不允许浮动
    toolbar2->setFloatable(false);

    // 设置不允许拖动
    // toolbar2->setMovable(false);

    QAction* action1 = new QAction("动作1");
    QAction* action2 = new QAction("动作2");
    QAction* action3 = new QAction("动作3");
    QAction* action4 = new QAction("动作4");

    toolbar1->addAction(action1);
    toolbar1->addAction(action2);
    toolbar2->addAction(action3);
    toolbar2->addAction(action4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

