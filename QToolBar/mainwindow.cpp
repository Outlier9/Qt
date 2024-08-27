#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QToolBar>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建菜单栏
    QMenuBar* menubar = this->menuBar();
    this->setMenuBar(menubar);
    //创建菜单
    QMenu* menu = new QMenu("文件");
    menubar->addMenu(menu);



    //创建工具栏
    QToolBar* toolbar = new QToolBar();

    this->addToolBar(toolbar);

    QAction* action1 = new QAction("保存");
    action1->setToolTip("点击这里保存文件");
    action1->setIcon(QIcon(":/1.jpg"));
    QAction* action2 = new QAction("打开");
    action2->setIcon(QIcon(":/2.jpg"));
    //菜单项设置到菜单中
    menu->addAction(action1);
    menu->addAction(action2);
    //菜单项设置到工具栏中
    toolbar->addAction(action1);
    toolbar->addAction(action2);

    connect(action1,&QAction::triggered,this,&MainWindow::handle);
    connect(action2,&QAction::triggered,this,&MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle()
{
    qDebug()<<"触发保存";
}

void MainWindow::close()
{
    qDebug()<<"触发打开";
}

