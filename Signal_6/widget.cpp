#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(200,200);

    connect(button,&QPushButton::clicked,this,[=](){
        qDebug()<<"lambda被执行了";
        button->move(200,300);
        this->move(100,100);
    });
}

Widget::~Widget()
{
    delete ui;
}

