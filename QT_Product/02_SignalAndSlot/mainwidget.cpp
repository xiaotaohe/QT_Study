#include "mainwidget.h"
#include<QPushButton>
#include<QtDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("abc");
    b2->move(50,50);

    //建立connect

    /* &b1:信号发出者，指针类型
     *  &QPushButton::pressed:处理信号，   &发送者的类名::信号名字
     * this：信号接收者
     * &MainWidget::close: 槽函数，信号处理函数    &接收的类名::槽函数名字
     */
   //系统槽函数
   //connect(&b1,&QPushButton::pressed,this,&MainWidget::close);


   /* 自定义槽函数，普通函数的用法
    * Qt5：任意成员函数，普通全局函数，静态函数
    * 由于信号处理没有返回值，所以，槽函数一定没有返回值
    */
    connect(b2,&QPushButton::released,this,&MainWidget::myslot);
    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);

    /* 信号，短信
     * 槽函数：接受短信的手机
     */
    //setWindowTitle("老大");
    this->setWindowTitle("老大");

    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(20,20);

    //显示子窗口
    //w.show();
    connect(&b3,&QPushButton::released,this,&MainWidget::ChangeWindow);

    //处理子窗口的信号
//    void (Subwidget::*funSignal)() = &Subwidget::mysignal;
//    connect(&w,funSignal,this,&MainWidget::dealSub);
//    void (Subwidget::*testSignal)(int,QString) = &Subwidget::mysignal;
//    connect(&w,testSignal,this,&MainWidget::dealSlot);


    //QT4信号连接
    //QT4槽函数必须有slots关键来修饰
    connect(&w,SIGNAL(mysignal()),this,SLOT(dealSub()));
    connect(&w,SIGNAL(mysignal(int,QString)),this,SLOT(dealSlot(int,QString)));
    resize(400,300);
}

MainWidget::~MainWidget()
{
       if(b2)
       {
           delete b2;
       }
}
void MainWidget::myslot()
{
    b2->setText("123");
}
void MainWidget:: ChangeWindow()
{
    //显示子窗口
    w.show();
    this->hide();
}

//处理子窗口发送的信号
void MainWidget:: dealSub()
{
    w.hide();
    show();
}

//处理子窗口的槽函数
void MainWidget:: dealSlot(int a,QString str)
{
    qDebug()<< a << str.toUtf8().data();
}
