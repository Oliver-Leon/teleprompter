#include "dropedit.h"

void DropEdit::dropEvent(QDropEvent *event)
{
    QTextEdit::dropEvent(event);
    this->clear();

    const QMimeData *mimeData = event->mimeData(); // 获取拖拽的数据
    if (mimeData->hasUrls())
    {

        QList<QUrl> urlList = mimeData->urls(); // 获取拖拽的URL列表
        if (urlList.length() > 1)
        {
            QMessageBox::warning(this, "警告", "目前只支持一次拖拽一个文件。");
            return;
        }

        QString filePath = urlList.at(0).toLocalFile();    // 获取第一个文件的本地路径
        QString fileSuffix = QFileInfo(filePath).suffix(); // 获取文件后缀名
        if (fileSuffix.toLower() != "txt")
        {
            QMessageBox::warning(this, "警告", "目前仅支持 txt 文件。");
            return;
        }
        // 读取txt文件内容
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, "错误", "无法打开文件：" + filePath);
            return;
        }

        QTextStream in(&file); // 创建文本流

        // 使用流式读取文本文件并加载到TextEdit中
        while (!in.atEnd())
        {
            QString line = in.readLine();
            this->append(line); // 将每行文本追加到TextEdit中
        }

        file.close();
    }
}
