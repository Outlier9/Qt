#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QMenuBar* menubar = new QMenuBar();
//    this->setMenuBar(menubar);
    //这种创建方式更合适，如果已存在创建好的menubar就返回，如果不存在就新创建
    //如果是获取到已经存在的QMenuBar,这里的设置就是自己替换自己还是自己,仍然在对象树上
    QMenuBar* menubar = this->menuBar();
    this->setMenuBar(menubar);

    QMenu* menu = new QMenu("菜单");

    menubar->addMenu(menu);

    QAction* action1 = new QAction("菜单项1");
    action1->setIcon(QIcon(":/1.jpg"));
    QAction* action2 = new QAction("菜单项2");
    action2->setIcon(QIcon(":/2.jpg"));
    menu->addAction(action1);
    menu->addAction(action2);


}

MainWindow::~MainWindow()
{
    delete ui;
}

