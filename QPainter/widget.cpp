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
    //实例化画家对象
    QPainter painter(this);

    //平移图片
    //painter.translate(100,100);

    //以（0,0）点开始画图，图片的尺寸跟原图保持一致
    //painter.drawPixmap(0,0,QPixmap(":/picture/1.jpg"));

    //以（10,10）点开始画图，图片的尺寸变为200*300
    painter.drawPixmap(10,10,200,300,QPixmap(":/picture/1.jpg"));


    //让图片的中心作为旋转的中心
    painter.translate(200,300);
    //顺时针旋转90度
    painter.rotate(90);
    //使原点复原
    painter.translate(-200,-300);
    painter.drawPixmap(0,0,200,300,QPixmap(":/picture/2.png"));


}

