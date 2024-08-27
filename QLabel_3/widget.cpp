#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 在构造函数中设置QLabel的属性
    // 对齐方式
    ui->label->setText("这是文本一");
    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // 自动换行
    ui->label_2->setText("这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 ");
    ui->label_2->setWordWrap(true);

    // 缩进
    ui->label_3->setText("这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 这是一段很长的文本 ");
    ui->label_3->setWordWrap(true);
    ui->label_3->setIndent(50);

    // 边距
    ui->label_4->setText("这是一段很长的文本 ");
    ui->label_4->setWordWrap(true);
    ui->label_4->setMargin(30);
}

Widget::~Widget()
{
    delete ui;
}

