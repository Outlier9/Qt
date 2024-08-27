#ifndef DIALOG_H
#define DIALOG_H
#include<QDialog>

#include <QWidget>

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget* parent);

    void handle();
};

#endif // DIALOG_H
