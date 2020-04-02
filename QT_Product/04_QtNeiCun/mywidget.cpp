#include "mywidget.h"
#include"mybutton.h"
#include<QPushButton>


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //Qt坐标系统：父窗口相对于屏幕，子窗口相对于父窗口
    //x: 以屏幕左上角向右递增
    //y: 一屏幕左上角向下递增
    move(0,0);
    resize(400,400);
    QPushButton* b = new QPushButton(this);
    b->move(200,200);
    b->setText("^_^");
    b->resize(200,100);

    QPushButton* b1 = new QPushButton(b);
    b1->move(20,10);
    b1->setText("@_@");
    b1->resize(50,50);

    //内存回收机制验证
    MyButton *b3 = new MyButton(this);
    b3->setText("123");

    //1)指定父对象后 2）直接或间接继承于Qobject
    //子对象如果是动态分配空间的new，不需要手动释放delete
    //系统会自动释放
}

MyWidget::~MyWidget()
{
}

