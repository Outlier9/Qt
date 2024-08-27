#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   a.setStyleSheet("QPushButton,QLabel,QLineEdit{color:red;}");

    Widget w;
    w.show();
    return a.exec();
}
