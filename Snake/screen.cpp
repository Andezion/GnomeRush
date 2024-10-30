#include "screen.h"
#include "cpoint.h"
#include <cstdarg>

static CPoint screenTopLeft;
static CPoint screenBottomRight;
static int cursorY, cursorX;

void initializeScreen()
{
    initscr();
    cbreak();
    noecho();
    timeout(20);
    nonl();
    leaveok(stdscr, TRUE);
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    curs_set(0);
}

void closeScreen()
{
    endwin();
}

void refreshScreen()
{
    getScreenAnchor(screenTopLeft.y, screenTopLeft.x);
    getScreenSize(screenBottomRight.y, screenBottomRight.x);
    screenBottomRight += screenTopLeft;
}

int nonBlockingGetch()
{
    return wgetch(stdscr);
}

void getScreenAnchor(int &y, int &x)
{
    getbegyx(stdscr, y, x);
}

void getScreenSize(int &y, int &x)
{
    getmaxyx(stdscr, y, x);
}

int moveToPosition(int y, int x)
{
    cursorY = y;
    cursorX = x;
    return (cursorY >= screenTopLeft.y && cursorY < screenBottomRight.y && cursorX >= screenTopLeft.x && cursorX < screenBottomRight.x);
}

void getCursorPosition(int& y, int& x)
{
    y = cursorY;
    x = cursorX;
}

void printChar(char c)
{
    if(c != '\n' && c != '\r')
    {
        if(cursorY >= screenTopLeft.y && cursorY < screenBottomRight.y && cursorX >= screenTopLeft.x && cursorX < screenBottomRight.x)
        {
            wmove(stdscr, cursorY, cursorX);
            addch(c);
        }
        cursorX++;
    }
}

int printLine(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    char dest[LINE_MAX];
    vsnprintf(dest, LINE_MAX, format, args);

    int i = 0;
    while(dest[i])
        printChar(dest[i++]);

    va_end(args);
    return !ERR;
}

