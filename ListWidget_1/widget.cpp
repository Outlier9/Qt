#include "widget.h"
#include "ui_widget.h"
# include<QDebug>
#include <QListWidgetItem>
//  注意加头文件，在头文件中也要加

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Java");
    ui->listWidget->addItem("Python");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
     if(current != NULL && previous != NULL)
     {
         qDebug() << "当前选中：" << current->text()
                  << "之前选中：" << previous->text();
     }
}

void Widget::on_pushButton_create_clicked()
{
    //获取到输入框内的内容
    const QString& text = ui->lineEdit->text();
    if(text.isEmpty())
    {
        return;
    }
    ui->listWidget->addItem(text);
}

void Widget::on_pushButton_delete_clicked()
{
    //获取当前被选中的元素
    int row = ui->listWidget->currentRow();
    //删除这一行
    ui->listWidget->takeItem(row);
}
