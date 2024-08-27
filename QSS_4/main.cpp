#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString style = "";
    style += "QComboBox::down-arrow{image:url(:/down.png)}";

    style += "QPushButton {color:red}";
    style += "QPushButton:hover {color:green}";
    style += "QPushButton:pressed {color:blue}";

    a.setStyleSheet(style);

    Widget w;
    w.show();
    return a.exec();
}
