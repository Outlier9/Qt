#include "widget.h"
#include "ui_widget.h"

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
    //获取到两个时间框的时间和日期
    QDateTime timeold = ui->dateTimeEdit_old->dateTime();
    QDateTime timenew = ui->dateTimeEdit_new->dateTime();
    //计算日期差值
    int days = timeold.daysTo(timenew);
    int hours = (timeold.secsTo(timenew)/3600) % 24;

    //设置 label的内容
    QString text = QString("在一起已经 ") + QString::number(days) + QString(" 天 零 ") + QString::number(hours) + QString(" 个小时！");
    ui->label->setText(text);
}
