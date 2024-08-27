#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFontDialog>
#include<QDebug>

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


void MainWindow::on_pushButton_clicked()
{
    //光标放在函数上按F1打开帮助文档
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok);
    qDebug() << "ok = " << ok;
//    qDebug() << font;
    qDebug() << font.family();//字体
    qDebug() << font.pointSize();//字号
    qDebug() << font.bold();//加粗
    qDebug() << font.italic();//倾斜

    ui->pushButton->setFont(font);
}
