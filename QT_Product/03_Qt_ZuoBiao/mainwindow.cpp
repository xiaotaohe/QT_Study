#include "mainwindow.h"
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
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

}

MainWindow::~MainWindow()
{
}

