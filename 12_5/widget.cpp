#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QTreeWidget
    // 设置跟节点的名称
    ui->treeWidget->setHeaderLabel("动物");

    // 新增顶层节点元素
    QTreeWidgetItem* item1 = new QTreeWidgetItem();
    // 每个节点可以设置多个列
    item1->setText(0, "猫");
    // 添加到顶层节点
    ui->treeWidget->addTopLevelItem(item1);

    QTreeWidgetItem* item2 = new QTreeWidgetItem();
    item2->setText(0, "狗");
    ui->treeWidget->addTopLevelItem(item2);

    QTreeWidgetItem* item3 = new QTreeWidgetItem();
    item3->setText(0, "鸟");
    ui->treeWidget->addTopLevelItem(item3);

    // 添加一些子节点
    QTreeWidgetItem* item4 = new QTreeWidgetItem();
    item4->setText(0, "中华田园猫");
    item1->addChild(item4);

    QTreeWidgetItem* item5 = new QTreeWidgetItem();
    item5->setText(0, "布偶猫");
    item1->addChild(item5);

    QTreeWidgetItem* item6 = new QTreeWidgetItem();
    item6->setText(0, "暹罗猫");
    item1->addChild(item6);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_insertTopItem_clicked()
{
    // 先获取输入框中的内容
    const QString& text = ui->lineEdit->text();
    // 构造 QTreeWidgetItem
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, text);
    // 添加到顶层节点
    ui->treeWidget->addTopLevelItem(item);
}

void Widget::on_pushButton_insertItem_clicked()
{
    // 先获取当前选中节点
    QTreeWidgetItem* current = ui->treeWidget->currentItem();
    if(current == nullptr)
        return;
    // 获取输入框内容
    const QString& text = ui->lineEdit->text();
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, text);
    // 插入到选中节点的子节点中
    current->addChild(item);
}

void Widget::on_pushButton_3_clicked()
{
    // 先获取当前选中的元素
    QTreeWidgetItem* current = ui->treeWidget->currentItem();
    if(current == nullptr)
        return;
    // 删除选中元素，需要先获取一下父节点，通过父节点来进行删除
    QTreeWidgetItem* parent = current->parent();
    if(parent == nullptr)
    {   // 顶层元素
        int index = ui->treeWidget->indexOfTopLevelItem(current);
        ui->treeWidget->takeTopLevelItem(index);
    }
    else
    {   // 普通元素
        parent->removeChild(current);
    }

}
