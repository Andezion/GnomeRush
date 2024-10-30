#ifndef SNAKE_SCREEN_H
#define SNAKE_SCREEN_H

#include <ncurses.h>

void initializeScreen();
void closeScreen();
void refreshScreen();

int nonBlockingGetch();

void getScreenAnchor(int &y, int &x);
void getScreenSize(int &y, int &x);

int moveToPosition(int y, int x);
void getCursorPosition(int& y, int& x);

void printChar(char c);
int printLine(const char* format, ...);


#endif //SNAKE_SCREEN_H
