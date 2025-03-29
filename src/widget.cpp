#include "widget.h"
#include "ui_widget.h"
#include "windowmanagement.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget), speed(500), isRollingPaused(false)
{
    ui->setupUi(this);
    ui->textEdit->setPlaceholderText("输入文本，或拖拽txt文件到此处~~\n已有文字设置大小时需选中文本~\n一次只能拖拽暂一个文件~\n暂时只支持txt文件~");
    this->window()->setAcceptDrops(true);
    connect(ui->win_top, &QCheckBox::clicked, this, [this](bool isclicked)
            { WindowManagement::setWindowTop(this->window()->winId(), isclicked); });
    connect(ui->win_capture, &QCheckBox::clicked, this, [this](bool isclicked)
            { WindowManagement::setWindowCaptured(this->window()->winId(), !isclicked); });
    connect(ui->transparent, &QSpinBox::valueChanged, this, [this](qreal value)
            {if(value>10.0)this->setWindowOpacity(value/100); });
    connect(ui->font_size, &QSpinBox::valueChanged, ui->textEdit, &QTextEdit::setFontPointSize); // 设置选中文字大小

    textEdit = ui->textEdit;
    timer = new QTimer(this);
    timer->setInterval(speed);
    // 这里建立定时器的信号槽连接
    connect(timer, &QTimer::timeout, this, &Widget::updateTextForTeleprompter);

    connect(ui->pushButton_start, &QPushButton::clicked, this, &Widget::startRolling);
    connect(ui->pushButton_stop, &QPushButton::clicked, this, &Widget::stopRolling);
    connect(ui->pushButton_increaseSpeed, &QPushButton::clicked, this, &Widget::increaseSpeed);
    connect(ui->pushButton_decreaseSpeed, &QPushButton::clicked, this, &Widget::decreaseSpeed);
    connect(ui->pushButton_highlight, &QPushButton::clicked, this, &Widget::highlightSelectedText);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateTextForTeleprompter()
{
    if (originalText.isEmpty())
        return;

    if (!isFinished)
    {
        QTextCursor cursor = textEdit->textCursor();
        cursor.setPosition(currentCharIndex);
        cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
        textEdit->setTextCursor(cursor);

        currentCharIndex++;
        if (currentCharIndex >= originalText.length())
        {
            isFinished = true;
            timer->stop();
        }
    }
}

void Widget::startRolling()
{
    if (!originalText.isEmpty() && isRollingPaused)
    {
        timer->start();
        isRollingPaused = false;
        isFinished = false;
    }
    else
    {
        originalText = textEdit->toPlainText();
        currentCharIndex = 0;
        timer->start();
        isFinished = false;
    }
}

void Widget::stopRolling()
{
    timer->stop();
    isRollingPaused = true;
}

void Widget::increaseSpeed()
{
    speed -= 100;
    if (speed < 100)
        speed = 100;
    timer->setInterval(speed);
}

void Widget::decreaseSpeed()
{
    speed += 100;
    timer->setInterval(speed);
}

void Widget::highlightSelectedText()
{
    QTextCursor cursor = ui->textEdit->textCursor(); // 获取当前光标
    if (cursor.hasSelection()) // 如果有选中的文本
    {
        QString selectedText = cursor.selectedText(); // 获取选中的文本
        QString highlightedText = QString("<span style='background-color: yellow;'>%1</span>")
                                      .arg(selectedText); // 创建高亮的 HTML 格式文本

        // 替换选中的文本为高亮格式
        cursor.insertHtml(highlightedText);
    }
}
