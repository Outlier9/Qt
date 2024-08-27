#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 通过ui->pushButton获取到界面上拖进去的这个按钮
    //connect(ui->pushButton,&QPushButton::clicked,this,&Widget::handleClicked);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    this->setWindowTitle("按钮已触发");
}
