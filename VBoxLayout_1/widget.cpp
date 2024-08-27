#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    QPushButton* btn3 = new QPushButton("按钮3");

    //创建布局管理器，并把按钮添加进去
    //如果创建的时候指定父元素为this，则后面不需要setLayout方法了
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);

    //把布局管理器设置到Widget中
    this->setLayout(layout);

}

Widget::~Widget()
{
    delete ui;
}

