#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建四个按钮
    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    QPushButton* btn3 = new QPushButton("按钮3");
    QPushButton* btn4 = new QPushButton("按钮4");

    //创建网格布局管理器，并添加元素
    QGridLayout* layout = new QGridLayout();
//    layout->addWidget(btn1,0,0);
//    layout->addWidget(btn2,0,1);
//    layout->addWidget(btn3,1,0);
//    layout->addWidget(btn4,1,1);

    //假如是这种布局
    layout->addWidget(btn1,0,1);
    layout->addWidget(btn2,0,2);
    layout->addWidget(btn3,0,3);
    layout->addWidget(btn4,0,4);

    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

