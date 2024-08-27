#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<mythread.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.创建子线程对象
    Generate* gen = new Generate;
    BubbleSort* bubble = new BubbleSort;
    QuickSort* quick = new QuickSort;


    connect(this,&MainWindow::starting,gen,&Generate::recvNum);

    //2.启动子线程
    connect(ui->start,&QPushButton::clicked,this,[=]()
    {
        emit starting(10000);
        gen->start();
    });

    //随机数子线程发送来的数据触发冒泡排序和快速排序接收数据
    connect(gen,&Generate::sendArray,bubble,&BubbleSort::recvArray);
    connect(gen,&Generate::sendArray,quick,&QuickSort::recvArray);


    //接收子线程发送的数据，显示在randlist里，同时启动两个排序子线程
    connect(gen,&Generate::sendArray,this,[=](QVector<int> list)
    {
        //启动两个子线程方法
        bubble->start();
        quick->start();

        for (int i=0; i<list.size(); ++i) {
            ui->randlist->addItem(QString::number(list.at(i)));
        }
    });

    //两个排序子线程处理数据
    connect(bubble,&BubbleSort::finish,this,[=](QVector<int> list)
    {
        for (int i=0; i<list.size(); ++i) {
            ui->bubblelist->addItem(QString::number(list.at(i)));
        }
    });
    connect(quick,&QuickSort::finish,this,[=](QVector<int> list)
    {
        for (int i=0; i<list.size(); ++i) {
            ui->quicklist->addItem(QString::number(list.at(i)));
        }
    });

    //资源释放
    connect(this,&MainWindow::destroyed,this,[=]()
    {
        //线程释放
        gen->quit();
        gen->wait();
        gen->deleteLater();

        bubble->quit();
        bubble->wait();
        bubble->deleteLater();

        quick->quit();
        quick->wait();
        quick->deleteLater();

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

