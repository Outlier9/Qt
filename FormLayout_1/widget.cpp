#include "widget.h"
#include "ui_widget.h"
#include<QFormLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFormLayout* layout = new QFormLayout();
    this->setLayout(layout);

    //创建三个label
    QLabel* label1 = new QLabel("姓名");
    QLabel* label2 = new QLabel("年龄");
    QLabel* label3 = new QLabel("电话");

    //创建三个lineEdit
    QLineEdit* lineEdit1 = new QLineEdit();
    QLineEdit* lineEdit2 = new QLineEdit();
    QLineEdit* lineEdit3 = new QLineEdit();

    //创建一个提交按钮
    QPushButton* btn = new QPushButton("提交");

    //把上述元素都添加到layout中
    layout->addRow(label1,lineEdit1);
    layout->addRow(label2,lineEdit2);
    layout->addRow(label3,lineEdit3);
    layout->addRow(NULL,btn);

}

Widget::~Widget()
{
    delete ui;
}

