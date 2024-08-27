#include "widget.h"
#include "ui_widget.h"
#include <fstream>
//注意头文件！！！
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //std::ifstream file("./config.txt");
    //相对路径，此时文件不是在D:\C C++\program\QT\ComboBox_2这个目录下
    //而是在运行程序目录"D:\C C++\program\QT\build-ComboBox_2-Desktop_Qt_5_14_0_MinGW_64_bit-Debug\config.txt"下
    std::ifstream file("D:/config.txt");
    if (!file.is_open()) {
            qDebug() << "Failed to open file";
            return;
        }
    std::string line;
    while(std::getline(file,line))
    {
        ui->comboBox->addItem(QString::fromStdString(line));
    }

    file.close();
}

Widget::~Widget()
{
    delete ui;
}

