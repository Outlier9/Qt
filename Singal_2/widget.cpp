#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->connect(button,&QPushButton::clicked,this,&Widget::handleClicked);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClicked()
{
    this->setWindowTitle("按钮已触发");
}

