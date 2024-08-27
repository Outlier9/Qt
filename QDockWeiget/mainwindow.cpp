#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDockWidget>
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDockWidget* dockwidget = new QDockWidget();
    this->addDockWidget(Qt::LeftDockWidgetArea,dockwidget);

    //给他设置标题
    dockwidget->setWindowTitle("浮动窗口");

    //给浮动窗口添加一些控件，不能直接给浮动窗口添加子控件
    //而是需要创建一个QWidget，控件添加到这个QWidget中
    //然后再把QWidget设置到dockWidget中
    QWidget* container = new QWidget();
    dockwidget->setWidget(container);

    //创建布局管理器并设置到QWidget中
    QVBoxLayout* layout = new QVBoxLayout();
    container->setLayout(layout);

    //创建其它控件添加到layout中
    QLabel* label = new QLabel();
    QPushButton* pushbtn = new QPushButton("按钮");

    layout->addWidget(label);
    layout->addWidget(pushbtn);

    //设置浮动窗口允许停放的位置
    dockwidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::TopDockWidgetArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

