#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //先创建一个菜单栏
    QMenuBar* menubar = new QMenuBar();
    this->setMenuBar(menubar);

    //设置菜单
    QMenu* menu1 = new QMenu("文件");
    QMenu* menu2 = new QMenu("编辑");
    QMenu* menu3 = new QMenu("视图");

    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);

    //设置菜单项
    QAction* action1 = new QAction("新建");
    QAction* action2 = new QAction("打开");
    QAction* action3 = new QAction("保存");
    QAction* action4 = new QAction("另存为");
    QAction* action5 = new QAction("退出");

    menu1->addAction(action1);
    menu1->addAction(action2);
    menu1->addAction(action3);
    menu1->addAction(action4);
    menu1->addAction(action5);

    //绑定槽函数
    connect(action1,&QAction::triggered,this,&MainWindow::handle);
    connect(action5,&QAction::triggered,this,&MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle()
{
    qDebug() << "触发新建操作";
}

void MainWindow::close()
{
    qDebug() << "触发退出操作";
}

