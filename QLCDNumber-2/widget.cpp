#include "widget.h"
#include "ui_widget.h"
#include<thread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lcdNumber->display("10");
//    int value = ui->lcdNumber->intValue();
//    while(true)
//    {
//        //先休眠1s
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        if(value<=0)
//        {
//            break;
//        }
//        value -= 1;
//        ui->lcdNumber->display(value);
          //循环会使Widget的构造函数无法执行完毕，此时界面是不能正确构造和显示的

//    }
    std::thread t([this] (){
        int value = ui->lcdNumber->intValue();
        while(true)
        {
            //先休眠1s
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if(value<=0)
            {
                break;
            }
            value -= 1;
            ui->lcdNumber->display(value);
        }

    });
    //另起一个线程，在新线程中完成循环+sleep
    //这个代码是有错误的，对于GUI上内容的操作，必须在主线程中完成
    //像Widget构造函数，以及connect连接的slot函数，都是在主线程中调用的,而我们自己创建的线程则不是
}

Widget::~Widget()
{
    delete ui;
}

