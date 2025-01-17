#include "widget.h"
#include "ui_widget.h"
#include <QNetworkDatagram>

const QString& SERVER_IP = "127.0.0.1";
const quint16 SERVER_PROT = 9090;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket = new QUdpSocket(this);
    this->setWindowTitle("客户端");
    // 通过信号槽来处理服务器返回的数据
    connect(socket, &QUdpSocket::readyRead, this, &Widget::processResponse);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    const QString& text = ui->lineEdit->text();
    // 构造 Udp 的请求数据
    QNetworkDatagram requestDatagram(text.toUtf8(), QHostAddress(SERVER_IP), SERVER_PROT);
    // 发送请求数据
    socket->writeDatagram(requestDatagram);
    // 把发送的请求添加到ListWidget中
    ui->listWidget->addItem("客服端: " + text);
    // 把输入框内容清空
    ui->lineEdit->setText("");
}

void Widget::processResponse()
{
    // 读取到相应数据
    const QNetworkDatagram responseDatagram = socket->receiveDatagram();
    QString response = responseDatagram.data();
    // 把响应的数据显示到界面上
    ui->listWidget->addItem("客户端: " + response);
}
