#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //开启定时器事件
    //timerId类似于文件描述符，是定时器的身份标识
    timerId = this->startTimer(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    //如果程序中存在多个定时器（startTimer创建的定时器），此时每个定时器都会触发timerEvent函数
    //先判定一下爱这次触发是否是想要的定时器触发的
    if(event->timerId() != this->timerId)
    {
        //如果不是我们的定时器就直接忽略
        //当前程序中只有一个定时器
        return;
    }
    int value = ui->lcdNumber->intValue();
    if(value <= 0)
    {
        //停止定时器
        this->killTimer(this->timerId);
        return;
    }
    value -= 1;
    ui->lcdNumber->display(value);
}

