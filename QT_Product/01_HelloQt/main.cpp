#include<QApplication>
#include<QWidget>//窗口控件基类
#include<QPushButton>//按钮

int main(int argc,char** argv)
{
    QApplication app(argc,argv);


    QWidget w;//窗体对象
    w.setWindowTitle("Hello Qt");//设置标题
    //w.show();

    QPushButton b;//按钮对象
    b.setText("^_^");
    //b.show();
    /*如果不指定对象，对象和对象（窗口和窗口）没有关系，独立
     * a指定b为它的对象，a放在b的上面
     *  1）setparent
     *  2）通过构造函数传参
     * 指定父对象，只需要父对象显示，上面的子对象自动显示
    */
    b.setParent(&w);
    //指定按钮b位置
    b.move(200,200);
    QPushButton b1(&w);
    b1.move(100,50);
    b1.setText("abc");
    w.show();
    app.exec();
    return 0;
}
