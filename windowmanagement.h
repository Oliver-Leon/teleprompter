#ifndef WINDOWMANAGEMENT_H
#define WINDOWMANAGEMENT_H
#include <Windows.h>
#include <WinUser.h>
#include <qwindowdefs.h>

class WindowManagement
{
private:
    WindowManagement();

public:
    static void setWindowTop(const WId &winId, bool isTop = true);
    static void setWindowCaptured(const WId &winId, bool canCaptured = false);
    static void setWindowTop(const HWND &hWnd, bool isTop = true);
    static void setWindowCaptured(const HWND &hWnd, bool canCaptured = false);
};

#endif // WINDOWMANAGEMENT_H
