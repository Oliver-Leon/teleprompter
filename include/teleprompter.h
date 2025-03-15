#ifndef TELEPROMPTER_H
#define TELEPROMPTER_H

#include <QWidget>
#include <QLabel>
#include <QStringList>
#include <QTimer>

class Teleprompter : public QWidget {
    Q_OBJECT // 必须包含此宏，以便支持信号和槽机制

public:
    explicit Teleprompter(QWidget *parent = nullptr); // 构造函数
    ~Teleprompter(); // 析构函数

private slots:
    void updateText(); // 更新文本的槽函数
    void increaseSpeed(); // 加快速度的槽函数
    void decreaseSpeed(); // 减慢速度的槽函数
    void setSpeed(int speed); // 设置速度的槽函数

private:
    QLabel *textLabel; // 用于显示文本的标签
    QString text; // 完整的文本
    QStringList words; // 文本分割后的单词列表
    int currentWordIndex; // 当前单词索引
    int scrollSpeed; // 滚动速度（毫秒）
    QTimer *timer; // 定时器
};

#endif // TELEPROMPTER_H
