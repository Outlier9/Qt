#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<mythread.h>
#include<QThread>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.创建子线程对象
    QThread* t1 = new QThread;
    QThread* t2 = new QThread;
    QThread* t3 = new QThread;

    //2.创建任务类的对象
    Generate* gen = new Generate;
    BubbleSort* bubble = new BubbleSort;
    QuickSort* quick = new QuickSort;

    //3.将任务对象移动到某个子线程中
    gen->moveToThread(t1);
    bubble->moveToThread(t2);
    quick->moveToThread(t3);

    connect(this,&MainWindow::starting,gen,&Generate::working);

    //2.启动子线程
    connect(ui->start,&QPushButton::clicked,this,[=]()
    {
        emit starting(10000);
        t1->start();
    });

    //随机数子线程发送来的数据触发冒泡排序和快速排序接收数据
    connect(gen,&Generate::sendArray,bubble,&BubbleSort::working);
    connect(gen,&Generate::sendArray,quick,&QuickSort::working);


    //接收子线程发送的数据，显示在randlist里，同时启动两个排序子线程
    connect(gen,&Generate::sendArray,this,[=](QVector<int> list)
    {
        //启动两个子线程方法
        t2->start();
        t3->start();

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
        t1->quit();
        t1->wait();
        t1->deleteLater();

        t2->quit();
        t2->wait();
        t2->deleteLater();

        t3->quit();
        t3->wait();
        t3->deleteLater();

        //任务对象释放
        gen->deleteLater();
        bubble->deleteLater();
        quick->deleteLater();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

