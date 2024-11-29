#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand(time(0));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_accept_clicked()
{
    ui->label->setText("好吧，那我接受你的追求");
}

void Widget::on_pushButton_reject_clicked()
{
//    int widch = this->geometry().width();
//    int height = this->geometry().height();

//    int x = rand() % widch;
//    int y = rand() % height;

//    ui->pushButton_reject->move(x,y);
}
// pressed 信号 鼠标按下时Button会立即重新生成坐标
void Widget::on_pushButton_reject_pressed()
{
    int widch = this->geometry().width();
    int height = this->geometry().height();

    int x = rand() % widch;
    int y = rand() % height;

    ui->pushButton_reject->move(x,y);
}
