#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColorDialog>
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
//    QColorDialog* dialog = new QColorDialog(this);
//    dialog->exec();
//    delete dialog;

    QColor color = QColorDialog::getColor(QColor(0,255,0),this,"选择颜色");
    qDebug() << color;

    //可以基于用户选择的颜色，修改窗口的颜色或者背景色
//    QString style = "background-color:rgb(" + QString::number(color.red()) + "," + QString::number(color.green())
//            + "," + QString::number(color.blue()) + ")";
    //用下面这种方式替换上述代码，更直观
    char style[1024] = {0};
    sprintf(style,"background-color:rgb(%d,%d,%d);",color.red(),color.green(),color.blue());

    //将选定的颜色设置到配置项中
    this->setStyleSheet(style);
}
