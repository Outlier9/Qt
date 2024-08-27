#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPlainTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void handleAction1();
    void handleAction2();

private:
    Ui::MainWindow *ui;

    QPlainTextEdit* edit; // 全局定义，否则handle函数无法访问
};
#endif // MAINWINDOW_H
