#include "widget.h"
#include "ui_widget.h"
#include<QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QIcon icon("C:/Users/hp/Desktop/f6ea4557e44fc81945a00d0f98d9eda.jpg");
    QIcon icon(":/icon.jpg");
    this->setWindowIcon(icon);

}

Widget::~Widget()
{
    delete ui;
}

