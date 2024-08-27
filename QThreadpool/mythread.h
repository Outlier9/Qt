#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include<QVector>
#include<QRunnable>

//生成随机数，将构造类的名字直接改成Generate更明确一些
class Generate :public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);

    //将主线程传递过来的数保存到m_num
    void recvNum(int num);
    void run() override;

signals:
    void sendArray(QVector<int>);

private:
    int m_num;

};


class BubbleSort :public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);

    //将主线程传递过来的数保存到m_num
    void recvArray(QVector<int> list);
    void run() override;

signals:
    void finish(QVector<int>);

private:
    QVector<int> m_list;

};

class QuickSort :public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);

    //将主线程传递过来的数保存到m_num
    void recvArray(QVector<int> list);
    void run() override;

private:
    void quickSort(QVector<int> &list,int l, int r);

signals:
    void finish(QVector<int>);

private:
    QVector<int> m_list;

};














#endif // MYTHREAD_H
