#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::handle);

    //启动定时器
    timer->start(100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    //获取到进度条的当前数据
    int value = ui->progressBar->value();
    if(value>=100)
    {
        timer->stop();
        return;
    }
    ui->progressBar->setValue(value+1);
}

