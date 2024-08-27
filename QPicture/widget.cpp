#include "widget.h"
#include "ui_widget.h"
#include<QPicture>
#include<QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPicture pic;
    QPainter painter;
    painter.begin(&pic); // 开始往pic绘图设备上绘画
    painter.setPen(QPen(Qt::red)); // 设置画笔颜色为红色
    painter.drawEllipse(QPoint(200,200),100,100);
    painter.end();//结束绘画
    pic.save("D:\\C C++\\program\\QT\\QPicture\\picture\\pic.pic");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //重现绘图指令
    QPicture pic;
    pic.load("D:\\C C++\\program\\QT\\QPicture\\picture\\pic.pic");
    painter.drawPicture(0,0,pic);
}

