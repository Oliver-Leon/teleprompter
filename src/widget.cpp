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
    connect(ui->pushButton_search, &QPushButton::clicked, this, &Widget::searchText);
    connect(ui->pushButton_clearHighlight, &QPushButton::clicked, this, &Widget::clearHighlights);

    // 初始化透明度和字体大小
    ui->transparent->setValue(100);
    ui->font_size->setValue(12);
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
    QTextCursor cursor = ui->textEdit->textCursor();
    if (cursor.hasSelection()) // 如果有选中的文本
    {
        // 获取当前选中文本的格式
        QTextCharFormat originalFormat = cursor.charFormat();
        QFont currentFont = originalFormat.font();
        qreal fontSize = currentFont.pointSizeF(); // 获取当前字体大小

        // 创建新的格式并保留字体大小
        QTextCharFormat format;
        format.setFont(currentFont); // 保留原有字体
        format.setFontPointSize(fontSize); // 显式设置字体大小
        format.setBackground(Qt::yellow); // 设置背景颜色为黄色

        // 应用新的格式
        cursor.mergeCharFormat(format);
    }
}

void Widget::searchText()
{
    QString keyword = ui->lineEdit_search->text();
    if (keyword.isEmpty())
        return;

    QTextDocument *document = ui->textEdit->document();
    QTextCursor cursor(document);

    clearHighlights();

    cursor.movePosition(QTextCursor::Start);

    bool found = false;
    while (!cursor.isNull() && !cursor.atEnd())
    {
        cursor = document->find(keyword, cursor, QTextDocument::FindCaseSensitively);
        if (!cursor.isNull())
        {
            found = true;
            // 传递匹配的起始位置而非结束位置
            highlightSearchResult(cursor.selectionStart(), keyword.length());
            cursor.movePosition(QTextCursor::Right); // 移动到下一个字符继续搜索
        }
    }

    if (!found)
    {
        QMessageBox::information(this, "搜索结果", "未找到关键词！");
    }
}

void Widget::highlightSearchResult(int startPos, int length)
{
    QTextCursor cursor(ui->textEdit->document());
    cursor.setPosition(startPos); // 定位到起始位置
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, length); // 选择指定长度的文本

    QTextCharFormat format;
    format.setBackground(Qt::green);
    cursor.mergeCharFormat(format);
}

void Widget::clearHighlights()
{
    QTextDocument *document = ui->textEdit->document(); // 获取文档对象
    QTextCursor cursor(document);                      // 创建光标对象

    // 移动光标到文档开头，并选择整个文档
    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);

    // 获取当前格式
    QTextCharFormat format = cursor.charFormat();

    // 清除背景颜色
    format.clearBackground();
    cursor.setCharFormat(format);
}
