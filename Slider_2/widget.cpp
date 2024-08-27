#include "widget.h"
#include "ui_widget.h"
#include<QShortcut> // 设置快捷键

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setText("");
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setSingleStep(10);
    ui->horizontalSlider->setValue(0);


    QShortcut* shortCut1 = new QShortcut(this);
    shortCut1->setKey(QKeySequence("-"));
    connect(shortCut1,&QShortcut::activated,this,&Widget::subValue);

    QShortcut* shortCut2 = new QShortcut(this);
    shortCut2->setKey(QKeySequence("="));
    connect(shortCut2,&QShortcut::activated,this,&Widget::addValue);
}

Widget::~Widget()
{
    delete ui;
}




void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setText(QString::number(value));

}


void Widget::subValue()
{
    int value = ui->horizontalSlider->value();
    ui->horizontalSlider->setValue(value-20);
}

void Widget::addValue()
{
    int value = ui->horizontalSlider->value();
    ui->horizontalSlider->setValue(value+20);
}




