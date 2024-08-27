#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QPushButton* button = new QPushButton(this);
//    button->setText("按钮");
//    button->setEnabled(false); // 禁用状态
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug() << "已触发";
}



void Widget::on_pushButton_enable_clicked()
{
    bool enabled = ui->pushButton->isEnabled();
    if(enabled)
    {
        ui->pushButton->setEnabled(false);

    }
    else
    {
        ui->pushButton->setEnabled(true);
    }
}
