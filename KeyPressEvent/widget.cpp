#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
//    qDebug() << event->key();
    if(event->key() == Qt::Key_A)
    {
        qDebug() << "按下A键有效";
    }

    if(event->key() == Qt::Key_B && event->modifiers() == Qt::ControlModifier)
    {
        qDebug() << "按下ctrl+B键有效";
    }
}

