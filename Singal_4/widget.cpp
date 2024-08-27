#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this,&Widget::mySignal,this,&Widget::hanleMySignal);

    //发送信号
    //发送信号的操作，也可以在任一合适的地方，不只是在构造函数中
    //emit mySignal();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::hanleMySignal(const QString& text)
{
    this->setWindowTitle(text);
}

void Widget::on_pushButton_clicked()
{
    emit mySignal("标题1");
}

void Widget::on_pushButton_2_clicked()
{
    emit mySignal("标题2");
}
