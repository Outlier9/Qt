#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QWidget* parent);
    //把⽣成代码中的构造函数改成带参数QWidget* 版本的构造函数,否则⽆法和QtDesigner⽣成的代码适配

    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void enterEvent(QEvent* e);
    void leaveEvent(QEvent* e);
};

#endif // MYPUSHBUTTON_H
