#include "widget.h"
#include "ui_widget.h"
#include<QVBoxLayout>
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);

    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");

    //创建Spacer
    QSpacerItem* spacer = new QSpacerItem(200,20);

    layout->addWidget(btn1);

    //在两个Widget中间件加上空白
    layout->addSpacerItem(spacer);

    layout->addWidget(btn2);
}

Widget::~Widget()
{
    delete ui;
}

