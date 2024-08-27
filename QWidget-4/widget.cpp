#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand(time(0)); // 用时间戳来获取随机数
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    ui->label->setText("kiss");
}

// 点击松开后移动
void Widget::on_pushButton_2_clicked()
{
//    // 移动按钮到随机位置
//    // 获取当前程序窗口位置
//    int width = this->geometry().width();
//    int height = this->geometry().height();
//    // 确保新得到的坐标在窗口内部，用余数得到的x一定<width
//    // rand函数使用前要设置随机种子
//    int x = rand() % width;
//    int y = rand() % height;

//    ui->label->setText("你再考虑考虑吧");

//    ui->pushButton_2->move(x,y);
}

// 点击按下就会移动
void Widget::on_pushButton_2_pressed()
{
    // 移动按钮到随机位置
    // 获取当前程序窗口位置
    int width = this->geometry().width();
    int height = this->geometry().height();
    // 确保新得到的坐标在窗口内部，用余数得到的x一定<width
    // rand函数使用前要设置随机种子
    int x = rand() % width;
    int y = rand() % height;

    ui->label->setText("你再考虑考虑吧");

    ui->pushButton_2->move(x,y);
}









