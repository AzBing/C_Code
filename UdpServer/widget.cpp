#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QNetworkDatagram>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket = new QUdpSocket(this);
    this->setWindowTitle("服务器");

    connect(socket, &QUdpSocket::readyRead, this, &Widget::processRequest);
    // 绑定端口号
    bool ret = socket->bind(QHostAddress::Any, 9090);
    if(!ret)
        QMessageBox::critical(this, "端口绑定失败", socket->errorString());
        return;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::processRequest()
{
    // 读取请求并解析
    const QNetworkDatagram& requestDatagram = socket->receiveDatagram();
    QString request = requestDatagram.data();
    // 根据请求计算相应
    const QString& response = process(request);
    // 把相应回显给客户端
    QNetworkDatagram responseDatagram(response.toUtf8(), requestDatagram.senderAddress(), requestDatagram.senderPort());
    socket->writeDatagram(responseDatagram);
    // 把交互的信息，显示到界面上
    QString log = "[" + responseDatagram.senderAddress().toString() + ":" + QString::number(requestDatagram.senderPort())
            + "] req: " + request + ", resp: " + response;

    ui->listWidget->addItem(log);
}

QString Widget::process(const QString &request)
{
    return request;
}

