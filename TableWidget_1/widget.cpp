#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建三行
    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);

    //创建三列
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);

    //设定列名
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("学号"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("姓名"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("年龄"));

    //设置初始数值
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("1001"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("张三"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("20"));

    ui->tableWidget->setItem(1,0,new QTableWidgetItem("1002"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("李四"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("21"));

    ui->tableWidget->setItem(2,0,new QTableWidgetItem("1003"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("王五"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("19"));


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_addrow_clicked()
{
    int rowcount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowcount);
}

void Widget::on_pushButton_addcolumn_clicked()
{
    int colcount = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(colcount);
    //设置列名
    const QString& name = ui->lineEdit->text();

    ui->tableWidget->setHorizontalHeaderItem(colcount,new QTableWidgetItem(name));
}

void Widget::on_pushButton_deleterow_clicked()
{
    int rowcount = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(rowcount);
}

void Widget::on_pushButton_deletecolumn_clicked()
{
    int curcol = ui->tableWidget->currentColumn();
    ui->tableWidget->removeColumn(curcol);
}


