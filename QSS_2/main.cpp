#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置全局样式
    QString style = "";

    //将所有按钮全局设置为黄色
    style += "QPushButton{color:yellow;}";
    //用id选择器设置第一个按钮为红色，第二个为绿色
    style += "#pushButton{color:red;}";
    style += "#pushButton_2{color:green;}";
    a.setStyleSheet(style);

    Widget w;
    w.show();
    return a.exec();
}
