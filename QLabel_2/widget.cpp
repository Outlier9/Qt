#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QResizeEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //先把QLabel设置成和窗口一样大，并把这个QLabel左上角设置成窗口左上角

    QRect windowRect = this->geometry();
    ui->label->setGeometry(0,0,windowRect.width(),windowRect.height());

    QPixmap pixmap(":/r.png");
    ui->label->setPixmap(pixmap);

    //设置自由拉伸
    ui->label->setScaledContents(true);
}

Widget::~Widget()
{
    delete ui;
}

// 形参enent包含了触发这个resize事件这一时刻窗口尺寸的数值
void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
    ui->label->setGeometry(0,0,event->size().width(),event->size().height());
}

