#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolBar* toolbar1 = new QToolBar();
    QToolBar* toolbar2 = new QToolBar();

    this->addToolBar(toolbar1);
    this->addToolBar(toolbar2);

    QAction* action1 = new QAction("动作1");
    QAction* action2 = new QAction("动作2");
    QAction* action3 = new QAction("动作3");
    QAction* action4 = new QAction("动作4");


    //菜单项设置到工具栏中
    toolbar1->addAction(action1);
    toolbar1->addAction(action2);
    toolbar2->addAction(action3);
    toolbar2->addAction(action4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

