#include "widget.h"
#include "ui_widget.h"
#include<QSound>

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


void Widget::on_pushButton_clicked()
{
    QSound* sound = new QSound(":/111.wav");
    sound->play();

    delete sound;
}
