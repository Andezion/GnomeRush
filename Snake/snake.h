#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "winsys.h"
#include "cpoint.h"
#include "screen.h"
#include <ctime>
#include <vector>
#include <list>

class SnakeGame : public FramedWindow
{
private:
    CPoint applePosition;
    CPoint snakePosition;
    CPoint snakeDirection;
    CPoint pauseDirection;
    int snakeSize;
    int timeLimit;
    int gameTimer;
    int score;
    int gameLevel;
    bool gameOver;
    bool gamePaused;
    bool showHelp;
    list<CPoint> previousPositions;

public:
    SnakeGame(CRect rect, char _symbol = ' ');
    void display();
    void spawnApple();
    void moveSnake(CPoint direction);
    bool handleEvent(int key);
    bool isWithinBounds();
    void pauseGame();
    void restartGame();
};

#endif //SNAKE_SNAKE_H
