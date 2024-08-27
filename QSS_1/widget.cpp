#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //应用到这个特定的按钮上
    //ui->pushButton->setStyleSheet("QPushButton{color:red;}");
    //ui->pushButton->setStyleSheet("QPushButton{color:#ffaa00;}");

    //应用到该窗口内全部的按钮上
    //this->setStyleSheet("QPushButton{color:red;}");


    ui->pushButton->setStyleSheet("QPushButton{color:black; font-size:50px;}");
    ui->pushButton_2->setStyleSheet("QPushButton{font-size:30px;}");



}

Widget::~Widget()
{
    delete ui;
}

