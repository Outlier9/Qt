#ifndef LABEL_H
#define LABEL_H
#include<QLabel>

#include <QWidget>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget* parent);

    //重写的时候，确保函数名字和函数的参数列表完全一致，形参名无所谓
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
};

#endif // LABEL_H
