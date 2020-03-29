#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include<QPushButton>

class Subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Subwidget(QWidget *parent = nullptr);
    void sendSlot();
signals:
    /*
     * 信号必须由(signals)这个关键子来声明
     * 信号没有返回值，但可以有参数
     * 信号就是函数的声明，只需声明，无需定义
     * 使用:emit mysignal();
     */
    void mysignal();
    void mysignal(int,QString);
private:
    QPushButton b;
signals:

};


#endif // SUBWIDGET_H
