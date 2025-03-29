#include "widget.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("隐身提示词");

    // 设置自动滚词的定时器
    QTimer *timer = new QTimer(&w);
    QObject::connect(timer, &QTimer::timeout, &w, [&w]() {
        w.updateTextForTeleprompter();
    });


    w.show();
    return a.exec();
}
