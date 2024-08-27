#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建图标对象
    QIcon icon(":/r.png");
    // 设置图标
    ui->pushButton_target->setIcon(icon);
    //设置尺寸
    ui->pushButton_target->setIconSize(QSize(80,80));

    ui->pushButton_up->setIcon(QIcon(":/Triangle3.png"));
    ui->pushButton_up->setIconSize(QSize(50,50));

    ui->pushButton_down->setIcon(QIcon(":/Triangle1.png"));
    ui->pushButton_down->setIconSize(QSize(50,50));

    ui->pushButton_left->setIcon(QIcon(":/Triangle4.png"));
    ui->pushButton_left->setIconSize(QSize(50,50));

    ui->pushButton_right->setIcon(QIcon(":/Triangle2.png"));
    ui->pushButton_right->setIconSize(QSize(50,50));

    // 设置快捷键
//    ui->pushButton_up->setShortcut(QKeySequence("ctrl+w"));
//    ui->pushButton_down->setShortcut(QKeySequence("s"));
//    ui->pushButton_left->setShortcut(QKeySequence("a"));
//    ui->pushButton_right->setShortcut(QKeySequence("d"));
    // 还可以使用按键的枚举设置快捷键
    ui->pushButton_up->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_W)); // 组合键
    ui->pushButton_down->setShortcut(QKeySequence(Qt::Key_S));
    ui->pushButton_left->setShortcut(QKeySequence(Qt::Key_A));
    ui->pushButton_right->setShortcut(QKeySequence(Qt::Key_D));

    // 键盘自带设置连发功能，鼠标需要手动开启
    ui->pushButton_up->setAutoRepeat(true);
    ui->pushButton_down->setAutoRepeat(true);
    ui->pushButton_left->setAutoRepeat(true);
    ui->pushButton_right->setAutoRepeat(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_up_clicked()
{
    // 获取到target位置
    QRect rect = ui->pushButton_target->geometry();
    // 设置新的位置
    ui->pushButton_target->setGeometry(rect.x(),rect.y()-5,rect.width(),rect.height());
}

void Widget::on_pushButton_down_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x(),rect.y()+5,rect.width(),rect.height());
}

void Widget::on_pushButton_left_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x()-5,rect.y(),rect.width(),rect.height());
}

void Widget::on_pushButton_right_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x()+5,rect.y(),rect.width(),rect.height());
}
