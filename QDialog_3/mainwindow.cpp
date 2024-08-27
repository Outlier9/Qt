#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog.h"

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
    //这是是Dialog类而不是QDialog类，因为此处要用自己定义的class
    Dialog* dialog = new Dialog(this); //如果要指定父窗口，就要加this
    dialog->resize(400,300);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}
