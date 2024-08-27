#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar* menubar = new QMenuBar();
    this->setMenuBar(menubar);

    QMenu* menu1 = new QMenu("文件(&F)");
    QMenu* menu2 = new QMenu("编辑(&V)");

    menubar->addMenu(menu1);
    menubar->addMenu(menu2);

    //需要用connect绑定槽函数
    QAction* action1 = new QAction("菜单项1(&Q)");
    QAction* action2 = new QAction("菜单项2(&W)");
    QAction* action3 = new QAction("菜单项3(&E)");
    QAction* action4 = new QAction("菜单项4(&R)");

    menu1->addAction(action1);
    menu1->addAction(action2);
    menu2->addAction(action3);
    menu2->addAction(action4);

    connect(action1,&QAction::triggered,this,&MainWindow::handle1);
    connect(action2,&QAction::triggered,this,&MainWindow::handle2);
    connect(action3,&QAction::triggered,this,&MainWindow::handle3);
    connect(action4,&QAction::triggered,this,&MainWindow::handle4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle1()
{
    qDebug() << "handle1";
}

void MainWindow::handle2()
{
    qDebug() << "handle2";
}

void MainWindow::handle3()
{
    qDebug() << "handle3";
}

void MainWindow::handle4()
{
    qDebug() << "handle4";
}



