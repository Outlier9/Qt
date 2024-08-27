#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabel("动物");

    QTreeWidgetItem* item1 = new QTreeWidgetItem();
    item1->setText(0,"猫");
    ui->treeWidget->addTopLevelItem(item1);

    QTreeWidgetItem* item2 = new QTreeWidgetItem();
    item2->setText(0,"狗");
    ui->treeWidget->addTopLevelItem(item2);

    QTreeWidgetItem* item3 = new QTreeWidgetItem();
    item3->setText(0,"鸟");
    ui->treeWidget->addTopLevelItem(item3);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_addtop_clicked()
{
    //获取输入框内容
    const QString& text = ui->lineEdit->text();
    if(text.isEmpty())
    {
        return;
    }
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0,text);
    ui->treeWidget->addTopLevelItem(item);
}

void Widget::on_pushButton_addclick_clicked()
{
    //获取输入框内容
    const QString& text = ui->lineEdit->text();
    if(text.isEmpty())
    {
        return;
    }
    //获取当前选中节点
    QTreeWidgetItem* currentitem = ui->treeWidget->currentItem();
    if(currentitem == NULL)
    {
        return;
    }
    //构造新的item
    QTreeWidgetItem* newitem = new QTreeWidgetItem();
    newitem->setText(0,text);
    //添加item到新节点
    currentitem->addChild(newitem);
    //展开父节点
    currentitem->setExpanded(true);
}

void Widget::on_pushButton_delect_clicked()
{
    QTreeWidgetItem* currentitem = ui->treeWidget->currentItem();
    if(currentitem == NULL)
    {
        return;
    }
    //获取当前节点的父节点
    QTreeWidgetItem* parent = currentitem->parent();
    if(parent==NULL)
    {
        //顶层节点
        int index = ui->treeWidget->indexOfTopLevelItem(currentitem);
        ui->treeWidget->takeTopLevelItem(index);
    }
    else
    {
        //非顶层节点
        parent->removeChild(currentitem);
    }
}
