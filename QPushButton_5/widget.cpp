#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString result = "今天你的安排是：";
    if(ui->checkBox->isChecked()){
        result += ui->checkBox->text() + " ";
    }
    if(ui->checkBox_2->isChecked()){
        result += ui->checkBox_2->text() + " ";
    }
    if(ui->checkBox_3->isChecked()){
        result += ui->checkBox_3->text() + " ";
    }
    ui->label->setText(result);
}
