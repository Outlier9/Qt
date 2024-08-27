#include "label.h"
#include<QDebug>
#include<QMouseEvent>

Label::Label(QWidget* parent):QLabel(parent)
{

}

void Label::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        qDebug()<<"按下左键";
    }
    else if(ev->button() == Qt::RightButton)
    {
        qDebug()<<"按下右键";
    }

    //当前event对象包含了鼠标点击位置的坐标
    qDebug()<<ev->x()<<','<< ev->y();
    //globalX和globalY是以屏幕左上角为原点获取的坐标
    qDebug()<<ev->globalX()<<','<< ev->globalY();
    qDebug() << "---------" ;
}

void Label::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        qDebug() <<"左键释放";
        qDebug() << "---------" ;
    }
    else if(ev->button() == Qt::RightButton)
    {
        qDebug() <<"右键释放";
        qDebug() << "---------" ;
    }
}

void Label::mouseDoubleClickEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        qDebug() << "-----双击左键----" ;
    }
    else if(ev->button() == Qt::RightButton)
    {
        qDebug() << "-----双击右键----" ;
    }
}
