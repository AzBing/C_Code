#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // tableWidget
    // 创建三行
    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);
    // 创建三列
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);
    // 给列设定列名称（设置水平方向的表头）
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("学号"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("姓名"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("年龄"));
    // 给表格中添加数据
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("101"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("张三"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("20"));

    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("102"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("李四"));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem("22"));

    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("103"));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem("王五"));
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem("23"));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_insertRow_clicked()
{
    // 获取当前一共有几行
    int rowCount = ui->tableWidget->rowCount();
    // 在最后一行插入
    // 传入的参数是下标，表示插入之后的行号
    ui->tableWidget->insertRow(rowCount);
}

void Widget::on_pushButton_deleteRow_clicked()
{
    int curRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(curRow);
}

void Widget::on_pushButton_insertColumn_clicked()
{
    // 先获取当前共有几列
    int colCount = ui->tableWidget->columnCount();
    // 在对应位置新增
    ui->tableWidget->insertColumn(colCount);
    // 设置列名
    const QString& text = ui->lineEdit->text();
    ui->tableWidget->setHorizontalHeaderItem(colCount, new QTableWidgetItem(text));
}

void Widget::on_pushButton_deleteColumn_clicked()
{
    int curCol = ui->tableWidget->currentColumn();
    ui->tableWidget->removeColumn(curCol);
}
