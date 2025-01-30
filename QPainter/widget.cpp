#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    // 绘图工作放到这里来执行
    (void) event;

    QPainter painter(this);
    // 画一个线段
    // painter.drawLine(20, 20, 200, 20);

    // painter.drawRect(100, 100, 200, 300);
    // painter.drawText(0, 100, " hello");
    QPen pen;
    // 设置红色线条
    pen.setColor(QColor(255, 0, 0));
    // 设置线条粗细
    pen.setWidth(5);
    // 设置线条风格
    pen.setStyle(Qt::DashLine);
    // 让 painter 对象应用 pen 对象
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(QColor(0, 255, 0));
    brush.setStyle(Qt::CrossPattern);
    painter.setBrush(brush);

    painter.drawEllipse(200, 200, 400, 100);
}

