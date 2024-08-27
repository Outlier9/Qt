#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //添加一个默认选项
    ui->man->setChecked(true);
    ui->label->setText("您选择的性别为：男");

    //禁用其他选项
    //setCheckable只能让按钮不被选中，仍然是可以相应点击事件的
    //ui->other->setCheckable(false);
    //推荐用下边两种之一
    ui->other->setEnabled(false);
    //ui->other->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_man_clicked()
{
    ui->label->setText("您选择的性别为男");
}

void Widget::on_woman_clicked()
{
    ui->label->setText("您选择的性别为女");
}

void Widget::on_other_clicked()
{
    ui->label->setText("您选择的性别为其他");
}
