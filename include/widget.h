#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QDragEnterEvent>
#include <QSpinBox>
#include <QDropEvent>
#include <QMimeData>
#include <QTextEdit>
#include <QTimer>
#include <QStringList>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


public slots:
    void updateTextForTeleprompter();
    void startRolling();
    void stopRolling();
    void increaseSpeed();
    void decreaseSpeed();
    void highlightSelectedText();
    void searchText();
    void clearHighlights();

private:
    Ui::Widget *ui;
    QTextEdit *textEdit;
    QString originalText;
    int currentCharIndex;
    QTimer *timer;
    int speed;
    bool isRollingPaused;
    bool isFinished;

    void highlightSearchResult(int position, int length);

};
#endif // WIDGET_H
