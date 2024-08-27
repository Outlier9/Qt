#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->horizontalSlider->setMinimum(500);
    ui->horizontalSlider->setMaximum(2000);
    ui->horizontalSlider->setSingleStep(100); //按下方向键的时候改变的步长
    ui->horizontalSlider->setValue(800);

    ui->verticalSlider->setMinimum(500);
    ui->verticalSlider->setMaximum(1500);
    ui->verticalSlider->setSingleStep(100); //按下方向键的时候改变的步长
    ui->verticalSlider->setValue(600);
    //翻转朝向，默认滑块从上往下增长
    ui->verticalSlider->setInvertedAppearance(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    QRect rect = this->geometry();
    this->setGeometry(rect.x(),rect.y(),value,rect.height());
    qDebug()<<value;
}

void Widget::on_verticalSlider_valueChanged(int value)
{
    QRect rect = this->geometry();
    this->setGeometry(rect.x(),rect.y(),rect.width(),value);
    qDebug()<<value;
}
