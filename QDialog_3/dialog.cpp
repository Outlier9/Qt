#include "dialog.h"
#include<QPushButton>
#include<QLabel>
#include<QVBoxLayout>

Dialog::Dialog(QWidget* parent):QDialog(parent)
{
    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);

    QLabel* label = new QLabel("这是一个对话框",this);
    QPushButton* pushbtn = new QPushButton("关闭",this);

    layout->addWidget(label);
    layout->addWidget(pushbtn);

    connect(pushbtn,&QPushButton::clicked,this,&Dialog::handle);
}

void Dialog::handle()
{
    this->close();
}
