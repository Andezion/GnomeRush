#include "windows.h"
#include "pong.h"

Window* myWin = new Window();
Pong* pong = new Pong();
Gamer* gamer1 = new Gamer();
Gamer* gamer2 = new Gamer();

LRESULT CALLBACK Proc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {

    case WM_CREATE:
    {
        pong->setup(gamer1, gamer2);
        SetFocus(hwnd);
    }break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        SelectObject(hdc, pong->getRed());
        MoveToEx(hdc, 350, 0, NULL);
        LineTo(hdc, 350, 500);

        SelectObject(hdc, pong->getBlack());
        SelectObject(hdc, pong->getWhite());
        Ellipse(hdc, pong->getBolPosX() - 9, pong->getBolPosY() - 9,
            pong->getBolPosX() + 9, pong->getBolPosY() + 9);

        SelectObject(hdc, pong->getHBlack());
        SelectObject(hdc, pong->getBlack());
        Rectangle(hdc, gamer1->getposX() - 5, gamer1->getposY() - 30,
            gamer1->getposX() + 5, gamer1->getposY() + 30);

        SelectObject(hdc, pong->getHBlack());
        SelectObject(hdc, pong->getBlack());
        Rectangle(hdc, gamer2->getposX() - 5, gamer2->getposY() - 30,
            gamer2->getposX() + 5, gamer2->getposY() + 30);

        SetBkMode(hdc, TRANSPARENT);
        SelectObject(hdc, pong->getScoreFont());

        TextOut(hdc, 680, 10, gamer1->getScoreString().c_str(), gamer1->getScoreString().length());


        TextOut(hdc, 10, 10, gamer2->getScoreString().c_str(), gamer2->getScoreString().length());

        EndPaint(hwnd, &ps);

    }break;

    case WM_CLOSE:
    {
        delete gamer1;
        delete gamer2;
        delete pong;
        DestroyWindow(hwnd);
    }break;

    case WM_DESTROY:
    {
        PostQuitMessage(0);
    }break;

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
        break;
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    myWin->setHinst(hInstance);

    if (!myWin->setWCE())
        return 1;

    RECT area = { 0, 0, 700, 500 };
    ::AdjustWindowRect(&area, WS_OVERLAPPEDWINDOW, FALSE);

    myWin->setWidth(area.right - area.left);
    myWin->setHeight(area.bottom - area.top);

    if (!myWin->createWindow())
        return 1;

    myWin->show(nCmdShow);

    myWin->messages(myWin->getHwnd(),
        gamer1, gamer2, pong);

    return 0;
}