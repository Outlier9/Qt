#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
//#include<stdio.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    printf("hello");
    //初始化第一个输入框，用来输入姓名
    ui->lineEdit_name->setPlaceholderText("请输入姓名");
    ui->lineEdit_name->setClearButtonEnabled(true);
    //初始化第二个输入框，用来输入密码
    ui->lineEdit_password->setPlaceholderText("请输入密码");
    ui->lineEdit_password->setClearButtonEnabled(true);
    //把显示模式设置成显示密码的模式
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    //初始化第三个输入框
    ui->lineEdit_phone->setPlaceholderText("请输入手机号");
    ui->lineEdit_phone->setClearButtonEnabled(true);
    //手机号有固定格式，此处的0代表数字
    ui->lineEdit_phone->setInputMask("000-0000-0000");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_submit_clicked()
{
    QString gender = ui->radioButton_nan->isChecked()?"男" :"女";
    qDebug()<<"姓名"<<ui->lineEdit_name->text()
           <<"密码"<<ui->lineEdit_password->text()
          <<"性别"<<gender
         <<"电话"<<ui->lineEdit_phone->text();
}
