#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("记事本");

    //获取到菜单栏
    QMenuBar* menubar = this->menuBar();
    QMenu* menu = new QMenu("文件");
    menubar->addMenu(menu);

    //添加菜单项
    QAction* action1 = new QAction("打开");
    QAction* action2 = new QAction("保存");
    menu->addAction(action1);
    menu->addAction(action2);

    edit = new QPlainTextEdit();
    QFont font;
    font.setPixelSize(20);
    edit->setFont(font);
    this->setCentralWidget(edit);

    //链接QAction的信号槽
    connect(action1,&QAction::triggered,this,&MainWindow::handleAction1);
    connect(action2,&QAction::triggered,this,&MainWindow::handleAction2);



}

MainWindow::~MainWindow()
{
    delete ui;
}


//打开
void MainWindow::handleAction1()
{
    //1.先弹出“打开文件”对话框，让用户选择打开哪个文件
    QString path = QFileDialog::getOpenFileName(this);

    //2.把文件名显示到状态栏里
    QStatusBar* statusbar = this->statusBar();
    statusbar->showMessage(path);

    //3.根据用户选择路径，构造一个QFile对象，并打开文件(只读)
    QFile file(path);
    bool ret = file.open(QIODevice::ReadOnly);

    //判断是否成功打开文件
    if(!ret)
    {
        statusbar->showMessage(path + "打开文件失败");
        return;
    }

    //4.读取文件
    QString text = file.readAll();
    // 返回的是QByteArray,可以用QString来实现相互转换（QString运算符重载提供了相关API）
    // 需要确保当前打开的文件是文本文件，如果是二进制文件就不合适

    //5.关闭文件！很重要，不关闭可能造成内存泄漏
    file.close();

    //6.读到的内容设置到输入框
    edit->setPlainText(text);
}

//保存
void MainWindow::handleAction2()
{

    //1.先弹出“保存文件”对话框，让用户选择打开哪个文件，这次使用的是getSaveFileName
    QString path = QFileDialog::getSaveFileName(this);

    //2.把文件名显示到状态栏里
    QStatusBar* statusbar = this->statusBar();
    statusbar->showMessage(path);

    //3.根据用户选择路径，构造一个QFile对象，并打开文件(写方式)
    QFile file(path);
    //bool ret = file.open(QIODevice::WriteOnly);
    bool ret = file.open(QFile::WriteOnly); // 这样也可以

    if(!ret)
    {
        statusbar->showMessage(path + "打开失败");
        return;
    }
    //4.写文件
    const QString& text = edit->toPlainText(); // 需要确保打开的是文本文件
    file.write(text.toUtf8());


    //5.关闭文件
    file.close();

}





