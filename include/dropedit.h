#ifndef DROPEDIT_H
#define DROPEDIT_H

#include <QObject>
#include <QTextEdit>
#include <QWidget>
#include <QDropEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QFileInfo>

class DropEdit : public QTextEdit
{
    using QTextEdit::QTextEdit;

protected:
    void dropEvent(QDropEvent *event) override;
};

#endif // DROPEDIT_H
