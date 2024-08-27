#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QMouseEvent>
#include<QWheelEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //把这个选项设置为true，才能追踪鼠标，设置为false的话，默认点击的时候才会追踪鼠标
    //this->setMouseTracking(true);//慎用

    total = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << event->x() << "," << event->y();
}

void Widget::wheelEvent(QWheelEvent *event)
{
    total+=event->delta();
    qDebug() << event->delta();
    qDebug() << total;
    qDebug() << "-------------";
}

