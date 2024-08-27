#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//不同于界面上的其他控件.此处QDialog每次按下按钮，都会创建一个新的QDialog对象，并进行显示
//每次点击都会创建新的对话框对象--->可能导致内存泄漏，尤其是内存剩余很少的时候
void MainWindow::on_pushButton_clicked()
{
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("(Dialog)");

    dialog->resize(400,300);

    dialog->show();

    //为解决内存泄漏问题，QDialog有一个属性可以使关闭按钮与delete关联起来
    dialog->setAttribute(Qt::WA_DeleteOnClose);
}
