#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置初始状态
    ui->lineEdit->setEchoMode(QLineEdit::Password);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        // true则是显示密码状态，就会把输入框的显示模式切换为normal
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        // false则是隐藏密码状态，就会把输入框的显示模式切换为Password
        ui->lineEdit->setEchoMode(QLineEdit::Password);
    }
}
