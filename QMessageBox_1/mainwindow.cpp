#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPushButton>
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
    //创建QMessageBox
    QMessageBox* messagebox = new QMessageBox();
    messagebox->setWindowTitle("标题");
    messagebox->setText("这是对话框的文本");
    messagebox->setIcon(QMessageBox::Warning);
    //标准按钮
    messagebox->setStandardButtons(QMessageBox::Ok | QMessageBox::Save | QMessageBox::Cancel);

    //自定义按钮
//    QPushButton* pushbtn = new QPushButton("按钮");
//    messagebox->addButton(pushbtn,QMessageBox::AcceptRole);

    //也可以connect连接信号槽，来针对当前点击的按钮进行一些相关操作

    //用户点击按钮，使对话框关闭以后，此时就能通过exec的返回值，来知道用户点击的哪个按钮，从而执行对应逻辑
    int result = messagebox->exec();

    if(result == QMessageBox::Ok)
    {
        qDebug()<<"Ok";
    }
    else if(result == QMessageBox::Save)
    {
        qDebug()<<"Save";
    }
    else if(result == QMessageBox::Cancel)
    {
        qDebug()<<"Cancel";
    }



    messagebox->setAttribute(Qt::WA_DeleteOnClose);

}
