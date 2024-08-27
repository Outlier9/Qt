#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<mythread.h>
#include<QThreadPool>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.创建任务对象
    Generate* gen = new Generate;
    BubbleSort* bubble = new BubbleSort;
    QuickSort* quick = new QuickSort;


    connect(this,&MainWindow::starting,gen,&Generate::recvNum);

    //2.启动子线程
    connect(ui->start,&QPushButton::clicked,this,[=]()
    {
        emit starting(10000);
        QThreadPool::globalInstance()->start(gen);
    });

    //随机数子线程发送来的数据触发冒泡排序和快速排序接收数据
    connect(gen,&Generate::sendArray,bubble,&BubbleSort::recvArray);
    connect(gen,&Generate::sendArray,quick,&QuickSort::recvArray);

    connect(gen,&Generate::sendArray,this,[=](QVector<int> list)
    {
        //启动两个任务
        QThreadPool::globalInstance()->start(bubble);
        QThreadPool::globalInstance()->start(quick);
        for (int i=0; i<list.size(); ++i) {
            ui->randlist->addItem(QString::number(list.at(i)));
        }
    });

    //两个排序处理数据
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



}

MainWindow::~MainWindow()
{
    delete ui;
}

