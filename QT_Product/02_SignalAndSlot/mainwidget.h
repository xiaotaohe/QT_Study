#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QPushButton>
#include"subwidget.h" //子窗口头文件
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
public slots:
    void myslot();
    void ChangeWindow();
    void dealSub();
    void dealSlot(int,QString);
private:
    //按钮b1 b2
    QPushButton b1;
    QPushButton* b2;
    QPushButton b3;
    Subwidget w;
};

#endif // MAINWIDGET_H
