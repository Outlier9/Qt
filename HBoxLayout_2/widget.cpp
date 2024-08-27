#include "widget.h"
#include "ui_widget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建顶层layout
    QVBoxLayout* layoutParent = new QVBoxLayout();
    this->setLayout(layoutParent);

    //添加两个按钮进去
    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");

    layoutParent->addWidget(btn1);
    layoutParent->addWidget(btn2);

    //创建子layout

    QHBoxLayout* layoutChild = new QHBoxLayout();

    //添加两个按钮进去
    QPushButton* btn3 = new QPushButton("按钮3");
    QPushButton* btn4 = new QPushButton("按钮4");

    layoutChild->addWidget(btn3);
    layoutChild->addWidget(btn4);

    //把子layout添加到父layout中
    layoutParent->addLayout(layoutChild);
}

Widget::~Widget()
{
    delete ui;
}

