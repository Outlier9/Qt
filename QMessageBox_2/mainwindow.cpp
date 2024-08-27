#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //快速创建对话框
    //warning类型
    int result = QMessageBox::warning(this,"对话框warning","对话框文本",QMessageBox::Ok,QMessageBox::Cancel);
    //critical类型
    //int result = QMessageBox::critical(this,"对话框critical","对话框文本",QMessageBox::Ok,QMessageBox::Cancel);
    //information类型
    //int result = QMessageBox::information(this,"对话框information","对话框文本",QMessageBox::Ok,QMessageBox::Cancel);
    if(result == QMessageBox::Ok)
    {
        qDebug()<<"Ok";
    }
    else if(result == QMessageBox::Cancel)
    {
        qDebug()<<"Cancel";
    }
}
