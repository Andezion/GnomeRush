#include "snake.h"

SnakeGame::SnakeGame(CRect rect, char _symbol /*= ' '*/):
        FramedWindow(rect, _symbol)
{
    srand(time(nullptr));
    applePosition = CPoint(rand() % geom.size.x + geom.topleft.x, rand() % geom.size.y + geom.topleft.y);
    snakePosition = CPoint(2, 2);
    snakeSize = 2;
    gameTimer = 0;
    timeLimit = 20;
    score = 0;
    gameLevel = 1;
    previousPositions.assign(snakeSize, snakePosition);
    gameOver = false;
    gamePaused = false;
    showHelp = false;
}

bool SnakeGame::handleEvent(int key)
{
    switch (key)
    {
        case KEY_UP:
            if (!(snakeDirection == CPoint (0, 1)) && !gamePaused) snakeDirection = CPoint(0, -1);
            return true;
        case KEY_DOWN:
            if (!(snakeDirection == CPoint (0, -1)) && !gamePaused) snakeDirection = CPoint(0, 1);
            return true;
        case KEY_RIGHT:
            if (!(snakeDirection == CPoint (-1, 0)) && !gamePaused) snakeDirection = CPoint(1, 0);
            return true;
        case KEY_LEFT:
            if (!(snakeDirection == CPoint (1, 0)) && !gamePaused) snakeDirection = CPoint(-1, 0);
            return true;
        case 'p':
            pauseGame();
            return true;
        case 'r':
            restartGame();
            return true;
        case 'h':
            showHelp = !showHelp;
            return true;
        case 'w':
            move(CPoint(0, -1));
            return true;
        case 'a':
            move(CPoint(0, 1));
            return true;
        case 's':
            move(CPoint(1, 0));
            return true;
        case 'd':
            move(CPoint(-1, 0));
            return true;
    };

    if ((timeLimit - (score * gameLevel)) >= gameTimer) {
        gameTimer++;
        return false;
    }
    gameTimer = 0;
    return true;
}

void SnakeGame::moveSnake(CPoint direction) {
    if (direction == false) {
        return;
    }
    previousPositions.push_front(snakePosition);
    snakePosition += direction;

    if (snakePosition.x <= geom.topleft.x) {
        snakePosition.x += geom.size.x;
    }
    if (snakePosition.x == geom.topleft.x + geom.size.x) {
        snakePosition.x = geom.topleft.x;
    }
    if (snakePosition.y <= geom.topleft.y) {
        snakePosition.y += geom.size.y;
    }
    if (snakePosition.y == geom.topleft.y + geom.size.y) {
        snakePosition.y = geom.topleft.y;
    }

    while (snakeSize < previousPositions.size()) {
        previousPositions.pop_back();
    }
}

void SnakeGame::display() {
    for (int y = geom.topleft.y; y < geom.topleft.y + geom.size.y; y++)
        for (int x = geom.topleft.x; x < geom.topleft.x + geom.size.x; x++)
        {
            gotoyx(y, x);
            printl("%c", symbol);
        }

    gotoyx(geom.topleft.y - 1, geom.topleft.x);
    const char* paused = (gamePaused) ? "PAUSED" : "";
    printl("LEVEL: %i APPLES: %i %s", gameLevel, score, paused);

    for (auto i = previousPositions.begin(); i != previousPositions.end(); ++i) {
        if (snakePosition.x == i->x && snakePosition.y == i->y && isWithinBounds()) {
            snakeDirection = CPoint(0, 0);
            gameOver = true;
        }
    }

    if (gameOver) {
        gotoyx(geom.topleft.y + 6, geom.topleft.x + 1);
        printl("%s", "THE SNAKE HAS DIED!!!");
    }
    else if (snakeDirection == CPoint(0, 0) && !gamePaused) {
        gotoyx(geom.topleft.y + 6, geom.topleft.x + 1);
        printl("%s", "p: Pause");
        gotoyx(geom.topleft.y + 8, geom.topleft.x + 1);
        printl("%s", "h: Help");
        gotoyx(geom.topleft.y + 10, geom.topleft.x + 1);
        printl("%s", "r: Restart");
        gotoyx(geom.topleft.y + 12, geom.topleft.x + 1);
        printl("%s", "Arrows: Control the Snake");
    } else {
        moveSnake(snakeDirection);
        if (showHelp) {
            gotoyx(geom.topleft.y + 14, geom.topleft.x + 1);
            printl("Snake Position: %i %i", snakePosition.x, snakePosition.y);
            gotoyx(geom.topleft.y + 13, geom.topleft.x + 1);
            printl("Window Position: %i %i", geom.topleft.x, geom.topleft.y);
            gotoyx(geom.topleft.y + 6, geom.topleft.x + 1);
            printl("%s", "p: Pause");
            gotoyx(geom.topleft.y + 8, geom.topleft.x + 1);
            printl("%s", "h: Help");
            gotoyx(geom.topleft.y + 10, geom.topleft.x + 1);
            printl("%s", "r: Restart");
            gotoyx(geom.topleft.y + 12, geom.topleft.x + 1);
            printl("%s", "Arrows: Control the Snake");
        }
    }

    for (auto i = previousPositions.begin(); i != previousPositions.end(); ++i) {
        gotoyx(i->y, i->x);
        printl("%c", '#');
    }

    gotoyx(snakePosition.y, snakePosition.x);
    printl("%c", '*');

    if (snakePosition == applePosition) {
        applePosition = CPoint(rand() % geom.size.x + geom.topleft.x, rand() % geom.size.y + geom.topleft.y);
        snakeSize++;
        score++;
    }
    spawnApple();
}

void SnakeGame::spawnApple() {
    gotoyx(applePosition.y, applePosition.x);
    printl("%c", 'O');
}

bool SnakeGame::isWithinBounds() {
    bool is_in_x = (snakePosition.x >= geom.topleft.x) && (snakePosition.x <= geom.topleft.x + geom.size.x);
    bool is_in_y = (snakePosition.y >= geom.topleft.y) && (snakePosition.y <= geom.topleft.y + geom.size.y);
    return (is_in_x && is_in_y);
}

void SnakeGame::pauseGame() {
    gamePaused = !gamePaused;
    if (pauseDirection == false) {
        pauseDirection = snakeDirection;
        snakeDirection.x = 0, snakeDirection.y = 0;
    } else {
        snakeDirection = pauseDirection;
        pauseDirection.x = 0, pauseDirection.y = 0;
    }
}

void SnakeGame::restartGame() {
    applePosition = CPoint(rand() % geom.size.x + geom.topleft.x, rand() % geom.size.y + geom.topleft.y);
    snakePosition = CPoint(2, 2);
    snakeSize = 2;
    gameTimer = 0;
    timeLimit = 20;
    score = 0;
    gameLevel = 1;
    previousPositions.clear();
    previousPositions.assign(snakeSize, snakePosition);
    snakeDirection.x = 0, snakeDirection.y = 0;
    gameOver = false;
    gamePaused = false;
    showHelp = false;
}

