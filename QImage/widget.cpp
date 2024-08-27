#include "widget.h"
#include "ui_widget.h"
#include<QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //绘图设备的大小为500*500，绘图格式为QImage::Format_RGB32
    //绘图格式可通过Qt助手查看
    QImage img(500,500,QImage::Format_RGB32);

    img.fill(Qt::white); // 填充色为白色，默认背景色为黑色

    QPainter painter(&img); //声明画家，画图设备为img

    painter.setPen(QPen(Qt::cyan));//设置画笔颜色为蓝绿色

    painter.drawEllipse(QPoint(200,200),100,100); //画圆
    //保存图片
    img.save("D:\\C C++\\program\\QT\\QImage\\img.jpg");

}

Widget::~Widget()
{
    delete ui;
}

