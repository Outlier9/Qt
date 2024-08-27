#include "mylabel.h"
#include<iostream>
#include<QDebug>
Mylabel::Mylabel(QWidget* parent):QLabel(parent)
{

}
Mylabel::~Mylabel()
{
    std::cout <<"Mylabel被销毁" << std::endl;
    qDebug() << "Mylabel被销毁";
}
