#include "teleprompter.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>

Teleprompter::Teleprompter(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("自动滚词提词器");

    textLabel = new QLabel(this);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet("font-size: 18px;");

    text = "这是一个示例文本，用于展示提词器的功能。它可以包含多个句子和单词。";
    words = text.split(" ");
    currentWordIndex = 0;

    scrollSpeed = 1000;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&QObject::deleteLater));
    connect(timer, &QTimer::timeout, this, &Teleprompter::updateText);
    timer->start(scrollSpeed);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textLabel);

    QPushButton *increaseSpeedButton = new QPushButton("加快速度", this);
    connect(increaseSpeedButton, &QPushButton::clicked, this, &Teleprompter::increaseSpeed);
    layout->addWidget(increaseSpeedButton);

    QPushButton *decreaseSpeedButton = new QPushButton("减慢速度", this);
    connect(decreaseSpeedButton, &QPushButton::clicked, this, &Teleprompter::decreaseSpeed);
    layout->addWidget(decreaseSpeedButton);

    QSlider *speedSlider = new QSlider(Qt::Horizontal, this);
    speedSlider->setRange(100, 3000);
    speedSlider->setValue(scrollSpeed);
    connect(speedSlider, &QSlider::valueChanged, this, &Teleprompter::setSpeed);
    layout->addWidget(speedSlider);
}

void Teleprompter::updateText()
{
    if (currentWordIndex < words.length())
    {
        textLabel->setText(textLabel->text() + " " + words[currentWordIndex]);
        currentWordIndex++;
    }
}

void Teleprompter::increaseSpeed()
{
    scrollSpeed -= 100;
    if (scrollSpeed < 100)
        scrollSpeed = 100;
    timer->start(scrollSpeed);
}

void Teleprompter::decreaseSpeed()
{
    scrollSpeed += 100;
    timer->start(scrollSpeed);
}

void Teleprompter::setSpeed(int speed)
{
    scrollSpeed = speed;
    timer->start(scrollSpeed);
}
