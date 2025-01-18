#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 添加标题
    this->setWindowTitle("客户端");
    // 创建实例
    socket = new QTcpSocket(this);
    // 和服务器建立连接
    socket->connectToHost("127.0.0.1", 9090);
    // 连接信号槽 处理响应
    connect(socket, &QTcpSocket::readyRead, this, [=]() {
        QString response = socket->readAll();
        ui->listWidget->addItem("服务器: " + response);
    });
    // 阻塞的去等待连接建立的结果 确认是否链接成功
    bool ret = socket->waitForConnected();
    if(!ret)
    {
        QMessageBox::critical(this, "连接服务器失败", socket->errorString());
        exit(1);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 获取输入框中内容
    const QString& text = ui->lineEdit->text();
    // 发送数据给服务器
    socket->write(text.toUtf8());
    // 把消息回显到界面上
    ui->listWidget->addItem("客户端: " + text);
    // 清空输入框
    ui->lineEdit->setText("");
}
