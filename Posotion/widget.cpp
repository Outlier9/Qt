#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("hello qt");
    button->move(200,300);

    this->move(200,300);
}

Widget::~Widget()
{
    delete ui;
}

