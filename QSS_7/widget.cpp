#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QPushButton* btn = new QPushButton(this);
//    btn->setGeometry(0,0,100,100);
//    btn->setText("hello");
//    btn->setStyleSheet("QPushButton{border:5px solid red;margin:20px;}");

//    const QRect& rect = btn->geometry();//获取按钮的几何位置和大小。
//    qDebug()<<rect;


}

Widget::~Widget()
{
    delete ui;
}

