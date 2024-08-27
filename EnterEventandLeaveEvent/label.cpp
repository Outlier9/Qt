#include "label.h"
#include<QDebug>

Label::Label(QWidget* parent):QLabel(parent)
{

}

void Label::enterEvent(QEvent *event)
{
    qDebug() << "enterEvent"<<endl;
}

void Label::leaveEvent(QEvent *event)
{
    qDebug() << "LeaveEvent"<<endl;
}
