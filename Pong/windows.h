#ifndef PONG_WINDOWS_H
#define PONG_WINDOWS_H

#include <Windows.h>
#include "pong.h"

LRESULT CALLBACK Proc(HWND, UINT, WPARAM, LPARAM);

class Window {
private:
    HINSTANCE hInst;
    MSG msg;
    LPWSTR windowName = L"Pong";              //вот название окна
    LPWSTR className = L"pingpong";
    WNDCLASSEXW wce;
    HWND hwnd;
    int width, height;
public:

    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    void setHinst(HINSTANCE hInst) {
        this->hInst = hInst;
    }

    void setWindowName(LPWSTR lpWindowName) {
        this->windowName = lpWindowName;
    }

    void setClassName(LPWSTR lpClassName) {
        this->className = lpClassName;
    }

    void setHwnd(HWND hwnd) {
        this->hwnd = hwnd;
    }

    int getWidth() {
        return this->width;
    }

    int getHeight() {
        return this->height;
    }

    HWND getHwnd() {
        return this->hwnd;
    }

    LPWSTR getWindowName() {
        return this->windowName;
    }

    LPWSTR getClassName() {
        return this->className;
    }

    HINSTANCE getHinst() {
        return this->hInst;
    }

    bool setWCE() {
        this->wce.cbSize = sizeof(WNDCLASSEX);
        wce.style = CS_HREDRAW | CS_VREDRAW;
        this->wce.hInstance = this->getHinst();
        this->wce.lpfnWndProc = Proc;
        this->wce.cbClsExtra = 0;
        this->wce.lpszClassName = this->getClassName();
        this->wce.hbrBackground = (HBRUSH)(BLACK_BRUSH);

        this->wce.hCursor = LoadCursor(NULL, IDC_ARROW);
        this->wce.cbWndExtra = 0;

        this->wce.lpszMenuName = NULL;

        if (!RegisterClassExW(&this->wce))
            return false;
        else
            return true;
    }

    bool createWindow() {
        this->setHwnd(CreateWindowExW(WS_EX_COMPOSITED, this->getClassName(), this->getWindowName(), WS_POPUP | WS_VISIBLE,
                                      (this->getWidth() / 2), (this->getHeight() / 2), this->getWidth(), this->getHeight(), NULL, NULL, this->getHinst(), NULL));

        if (!this->getHinst())
            return false;
        else
            return true;
    }

    void show(int iCmdShow) {
        ShowWindow(this->getHwnd(), iCmdShow);
        UpdateWindow(this->getHwnd());
    }

    int messages(HWND hwnd, Gamer* gamer1, Gamer* gamer2, Pong* pong) {
        while (true) {

            srand(GetTickCount());

            while (PeekMessage(&this->msg, 0, 0, 0, PM_REMOVE)) {
                TranslateMessage(&this->msg);
                DispatchMessage(&this->msg);
            }

            if (this->msg.message == WM_QUIT)
                break;

            pong->setTime(GetTickCount());

            while (GetTickCount() - pong->getTime() < 5);

            pong->input(gamer1, gamer2);
            pong->moverBol(gamer1, gamer2);

            InvalidateRect(hwnd, NULL, true);
        }

        return (int)this->msg.wParam;
    }

};

#endif //PONG_WINDOWS_H
