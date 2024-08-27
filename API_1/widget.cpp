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
    //实例化画家对象，this表示的是在当前窗口中绘画，即绘图设备
    QPainter painter(this);


    //设置画笔
    QPen pen(QColor(255,0,0));
    //设置画笔宽度
    pen.setWidth(3);
    //设置画笔风格
    pen.setStyle(Qt::DashLine);
    //设置让画家使用画笔
    painter.setPen(pen);


    //设置画刷，给封闭图形填充颜色
    QBrush brush(Qt::cyan);
    //设置画刷风格
    brush.setStyle(Qt::Dense1Pattern);
    //让画家使用画刷
    painter.setBrush(brush);



    //画一条线
    painter.drawLine(QPoint(20,20),QPoint(200,20));

    //再画一条线
    painter.drawLine(20,100,200,100);

    //绘制矩形
    painter.drawRect(120,120,100,50);

    //绘制圆
    painter.drawEllipse(QPoint(400,200),50,50);



    //绘制文本
    QFont font("华文行楷",24);
    painter.setFont(font);

    //设置画笔颜色
    painter.setPen(Qt::blue);

    //画文字
    painter.drawText(QRect(100,200,600,150),"Outlier9");
}

