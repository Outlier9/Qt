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
    disconnect(ui->pushButton,&QPushButton::clicked,this,&Widget::on_pushButton_2_clicked);
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::on_pushButton_clicked);
    this->setWindowTitle("1");
}

void Widget::on_pushButton_2_clicked()
{
    // 先断开原来的pushButton原来的信号槽
    disconnect(ui->pushButton,&QPushButton::clicked,this,&Widget::on_pushButton_clicked);
    // 重新绑定信号槽
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::on_pushButton_2_clicked);
    this->setWindowTitle("2");
}
