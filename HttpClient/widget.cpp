#include "widget.h"
#include "ui_widget.h"
#include <QNetworkReply>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");
    manager = new QNetworkAccessManager(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // 获取到输入框中的 URL
    QUrl url(ui->lineEdit->text());
    // 构造一个 Http 请求
    QNetworkRequest request(url);
    // 发送请求
    QNetworkReply* response = manager->get(request);
    // 通过信号槽来响应
    connect(response, &QNetworkReply::finished, this, [=]() {
        if(response->error() == QNetworkReply::NoError)
        {
            // 响应正确
            QString html = response->readAll();
            ui->plainTextEdit->setPlainText(html);
        }
        else
        {
            // 响应出错
            ui->plainTextEdit->setPlainText(response->errorString());
        }
        response->deleteLater();
    });
}





