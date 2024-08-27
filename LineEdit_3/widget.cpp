#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("请输入密码，两次密码要填写一致！");
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    (void) arg1;
    const QString& s1 = ui->lineEdit->text();
    const QString& s2 = ui->lineEdit_2->text();
    if(s1.isEmpty() && s2.isEmpty())
    {
        ui->label->setText("密码为空！");
    }
    else if(s1 == s2){
        ui->label->setText("两次输入的密码相同！");
    }
    else
    {
        ui->label->setText("两次输入的密码不相同！");
    }
}

void Widget::on_lineEdit_2_textEdited(const QString &arg1)
{
    (void) arg1;
    const QString& s1 = ui->lineEdit->text();
    const QString& s2 = ui->lineEdit_2->text();
    if(s1.isEmpty() && s2.isEmpty())
    {
        ui->label->setText("密码为空！");
    }
    else if(s1 == s2){
        ui->label->setText("两次输入的密码相同！");
    }
    else
    {
        ui->label->setText("两次输入的密码不相同！");
    }
}
