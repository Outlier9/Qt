#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

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


void Widget::on_radioButton_clicked(bool checked)
{
    //checked表示当前被选中的状态
    qDebug() << "clicked:" << checked;
}

void Widget::on_radioButton_2_clicked()
{
    //checked表示当前被选中的状态
    qDebug() << "pressed";
}

void Widget::on_radioButton_3_clicked()
{
    //checked表示当前被选中的状态
    qDebug() << "released";
}

void Widget::on_radioButton_4_toggled(bool checked)
{
    //checked表示当前被选中的状态
    qDebug() << "toggled:" << checked;
}
