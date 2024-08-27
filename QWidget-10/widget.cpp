#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //访问到图片文件
    QPixmap pixmap(":/1.jpg");
    // 用函数对图片进行缩放，不是修改图像本身，结果会返回一个图片所以需要再次赋值给pixmap
    pixmap = pixmap.scaled(100,100);
    //热点位置,以左上角为原点，设置10,10的位置是实际点击位置
    QCursor cursor(pixmap,10,10);
    //把光标设置进去
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

