#include "widget.h"
#include "ui_widget.h"
#include<QPainter>

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

void Widget::paintEvent(QPaintEvent *)
{
    //实例化
    QPainter painter(this);
    QImage img;
    img.load(":/picture/3.png");

    //修改像素点
    for (int i = 100;i < 200; i++) {
        for (int j = 100;j < 200; j++) {
            QRgb rgb = qRgb(0,0,255);
            img.setPixel(i,j,rgb);
        }
    }

    painter.drawImage(0,0,img);
}

