#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QFileInfo>
#include<QFileDialog>

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
    //弹出文件对话框并获取文件属性信息
    QString path = QFileDialog::getOpenFileName(this);
    //构造出一个QFileInfo对象
    QFileInfo fileInfo(path);

    //打印信息
    qDebug() << fileInfo.fileName();
    qDebug() << fileInfo.suffix();
    qDebug() << fileInfo.path();
    qDebug() << fileInfo.size();
    qDebug() << fileInfo.isFile();
    qDebug() << fileInfo.isDir();


}
