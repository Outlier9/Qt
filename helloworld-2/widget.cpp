#include<QLabel>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QLabel* label = new QLabel(this); //更推荐这种方式，在堆上创建，给当前一个对象指定一个“父对象”
    //label->setText("helloworld"); //设置空间中，要显示的文本
    QLabel label(this); //第二种写法
    label.setText("helloworld");

}

Widget::~Widget()
{
    delete ui;
}

