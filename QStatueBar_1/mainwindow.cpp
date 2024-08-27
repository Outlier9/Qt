#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QProgressBar>
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //存在就获取，不存在就创建
    QStatusBar* statusbar = this->statusBar();
    //如果状态栏没有被创建，这样的设置是必要的
    //如果状态栏已经在窗口中存在，这样的设置其实意义不大，但是也没副作用,仍然保留
    this->setStatusBar(statusbar);

    //显示一个临时信息
    //statusbar->showMessage("这是一个消息",3000); //  timeout参数：这个3000表示3秒后自动消失，不填会持久存在

    //给状态栏添加一个子控件
    QLabel* label = new QLabel("子控件1");
    statusbar->addWidget(label);

    QLabel* label2 = new QLabel("子控件2");
    statusbar->addWidget(label2);
    QLabel* label3 = new QLabel("子控件3");
    statusbar->addWidget(label3);

    //进度条控件
    QProgressBar* progressbar = new QProgressBar();
    progressbar->setRange(0,100);
    progressbar->setValue(50);
    statusbar->addWidget(progressbar);

    //按钮控件
    QPushButton* pushbtn = new QPushButton("按钮");
    //从右往左放置
    statusbar->addPermanentWidget(pushbtn);
}

MainWindow::~MainWindow()
{
    delete ui;
}

