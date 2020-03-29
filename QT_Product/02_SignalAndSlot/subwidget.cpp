#include "subwidget.h"

Subwidget::Subwidget(QWidget *parent) : QWidget(parent)
{
       this->setWindowTitle("小弟");
        b.setParent(this);
        b.setText("切换到主窗口");
        connect(&b,&QPushButton::clicked,this,&Subwidget::sendSlot);
        resize(400,300);
}
 void Subwidget:: sendSlot()
 {
     emit mysignal();
     emit mysignal(250,"我是子窗口");
 }
