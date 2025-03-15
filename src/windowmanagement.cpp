#include "windowmanagement.h"

#ifdef Q_CC_MSVC
#pragma comment(lib, "user32.lib") // 这条预处理是MSVC的语法，若使用MinGW编译，请修改配置文件，在配置文件中链接库//参考：https://blog.csdn.net/qqwangfan/article/details/105512532
#endif

WindowManagement::WindowManagement() {}

void WindowManagement::setWindowTop(const WId &winId, bool isTop)
{
    WindowManagement::setWindowTop(reinterpret_cast<HWND>(winId), isTop);
}

void WindowManagement::setWindowCaptured(const WId &winId, bool canCaptured)
{
    WindowManagement::setWindowCaptured(reinterpret_cast<HWND>(winId), canCaptured);
}

void WindowManagement::setWindowTop(const HWND &hWnd, bool isTop)
{
    if (isTop)
        SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); // 窗口置顶
    else
        SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); // 取消置顶
}

void WindowManagement::setWindowCaptured(const HWND &hWnd, bool canCaptured)
{
    if (canCaptured)
        SetWindowDisplayAffinity(hWnd, WDA_NONE); // 允许捕获
    else
        SetWindowDisplayAffinity(hWnd, WDA_EXCLUDEFROMCAPTURE); // 禁止捕获
}
