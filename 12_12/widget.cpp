#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

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


void Widget::on_textEdit_textChanged()
{
    qDebug() << "testChanged" << ui->textEdit->toPlainText();
}


// 打印所选中的文本
void Widget::on_textEdit_selectionChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    qDebug() << "selectionChanged" << cursor.selectedText();
}

// 输入框光标位置发生改变 触发信号
void Widget::on_textEdit_cursorPositionChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    qDebug() << "cursorPositionChanged: " << cursor.position();
}

void Widget::on_textEdit_undoAvailable(bool b)
{
    qDebug() << "undoAvailable: " << b;
}

void Widget::on_textEdit_redoAvailable(bool b)
{
    qDebug() << "redoAvailable: " << b;
}

void Widget::on_textEdit_copyAvailable(bool b)
{
    qDebug() << "copyAvailable: " << b;
}
