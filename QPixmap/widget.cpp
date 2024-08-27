#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Pixmap绘图设备，绘图设备尺寸为500*500
    QPixmap pix(500,500);
    //实例化画家对象
    QPainter painter(&pix);
    //设置画笔颜色
    painter.setPen(Qt::red);
    //画图
    painter.drawEllipse(QPoint(100,100),100,100);
    //保存绘制的图片
    pix.save("D:\\C C++\\program\\QT\\QPainter\\picture\\pix.png");
}

Widget::~Widget()
{
    delete ui;
}

