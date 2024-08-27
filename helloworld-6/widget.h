#ifndef WIDGET_H
#define WIDGET_H
#include<QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void handleClick();

private:
    Ui::Widget *ui;
    QPushButton* myButton;
};
#endif // WIDGET_H
