#ifndef PONG_PONG_H
#define PONG_PONG_H

#include <Windows.h>
#include <ctime>
#include <string>

using namespace std;

class Gamer {
private:
    int posX, posY, score;
    RECT rect;
public:

    Gamer() {
        this->posX = 0;
        this->posY = 0;
        this->rect.left = 0;
        this->rect.right = 0;
        this->rect.top = 0;
        this->rect.bottom = 0;
        this->score = 0;
    }

    void setRect(int x, int y, int w, int h) {
        rect.left = x;
        rect.right = y;
        rect.top = w;
        rect.bottom = h;
    }

    void setposX(int posX) {
        this->posX = posX;
    }
    void setposY(int posY) {
        this->posY = posY;
    }
    void setScore(int score) {
        this->score = score;
    }

    int getScore() {
        return this->score;
    }

    string getScoreString() {
        return std::to_string(this->score);
    }

    int getposX() {
        return this->posX;
    }
    int getposY() {
        return this->posY;
    }

};

class Pong {

private:
    HPEN red, green, blue, black;
    HBRUSH white, hBlue, hGreen, hBlack;
    int gamer1PosX, gamer1PosY, gamer2PosX, gamer2PosY;
    int bolPosX, bolPosY, directX, directY;
    HFONT scoreFont;
    HBITMAP metal;
    HBRUSH hMetal;

    DWORD timeStart;

public:

    Pong() {
        this->setBolPosX(350);
        this->setBolPosY(250);
    }

    HFONT getScoreFont() {
        return this->scoreFont;
    }

    HBRUSH getWhite() {
        return this->white;
    }

    HBRUSH getBlack() {
        return this->hBlack;
    }

    HBRUSH getHBlue() {
        return this->hBlue;
    }

    HBRUSH getHGreen() {
        return this->hGreen;
    }

    HPEN getRed() {
        return this->red;
    }

    HPEN getBlue() {
        return this->blue;
    }

    HPEN getGreen() {
        return this->green;
    }

    HPEN getHBlack() {
        return this->black;
    }

    int getGamer1PosX() {
        return this->gamer1PosX;
    }

    int getGamer1PosY() {
        return this->gamer1PosY;
    }

    int getGamer2PosX() {
        return this->gamer2PosX;
    }

    int getGamer2PosY() {
        return this->gamer2PosY;
    }

    int getBolPosX() {
        return this->bolPosX;
    }

    int getBolPosY() {
        return this->bolPosY;
    }

    int getDirectX() {
        return this->directX;
    }

    int getDirectY() {
        return this->directY;
    }

    DWORD getTime() {
        return this->timeStart;
    }

    void setTime(DWORD time) {
        this->timeStart = time;
    }

    void setBolPosX(int bolPosX) {
        this->bolPosX = bolPosX;
    }

    void setBolPosY(int bolPosY) {
        this->bolPosY = bolPosY;
    }

    void setDirectX(int x) {
        this->directX = x;
    }

    void setDirectY(int y) {
        this->directY = y;
    }

    void setup(Gamer* gamer1, Gamer* gamer2) {
        this->red = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
        this->green = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
        this->blue = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
        this->black = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
        this->white = CreateSolidBrush(RGB(255, 255, 255));
        this->hBlack = CreateSolidBrush(RGB(0, 0, 0));
        this->hBlue = CreateSolidBrush(RGB(0, 0, 255));
        this->hGreen = CreateSolidBrush(RGB(0, 255, 0));
        this->scoreFont = CreateFont(20, 0, 0, 0, FW_BOLD,
                                     FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                     OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, NULL);

        gamer1->setposX(30);
        gamer1->setposY(225 - 20);

        gamer2->setposX(700 - 30);
        gamer2->setposY(225 - 20);

        gamer1->setRect(175 - 30, 175 + 50, 20, 40);
        gamer2->setRect(175 * 3 - 50, 175 * 3 + 50, 20, 40);
    }

    void input(Gamer* gamer1, Gamer* gamer2) {

        /* first gamer */
        if (GetAsyncKeyState(0x41) && gamer1->getposY() > 0)
            gamer1->setposY(gamer1->getposY() - 10);
        if (GetAsyncKeyState(0x5A) && gamer1->getposY() < 460)
            gamer1->setposY(gamer1->getposY() + 10);

        /* second gamer */
        if (GetAsyncKeyState(VK_UP) && gamer2->getposY() > 0)
            gamer2->setposY(gamer2->getposY() - 10);
        if (GetAsyncKeyState(VK_DOWN) && gamer2->getposY() < 460)
            gamer2->setposY(gamer2->getposY() + 10);

        /* start game */
        if (GetAsyncKeyState(VK_SPACE)
            && this->getBolPosX() == 350
            && this->getBolPosY() == 250) {
            if (rand() % 10 < 5)
                this->setDirectX(-5);
            else
                this->setDirectX(5);

            if (rand() & 10 < 5)
                this->setDirectY(-5);
            else
                this->setDirectY(5);
        }

        /* exit */
        if (GetAsyncKeyState(VK_ESCAPE))
            PostQuitMessage(0);
    }

    void moverBol(Gamer* gamer1, Gamer* gamer2) {


        if (this->getBolPosX() + this->getDirectX() >= 700) {
            this->setBolPosX(350);
            this->setBolPosY(250);
            this->setDirectX(0);
            this->setDirectY(0);
            gamer2->setScore(gamer2->getScore() + 1);
        }

        if (this->getBolPosX() + this->getDirectX() <= 0) {
            this->setBolPosX(350);
            this->setBolPosY(250);
            this->setDirectX(0);
            this->setDirectY(0);
            gamer1->setScore(gamer1->getScore() + 1);
        }


        if (this->getBolPosX() + this->getDirectX() <= gamer1->getposX() + 9
            &&
            (this->getBolPosY() <= gamer1->getposY() + 30
             && this->getBolPosY() >= gamer1->getposY() - 30)
                ) {
            this->setDirectX(-this->getDirectX());
        }


        if (this->getBolPosX() + this->getDirectX() >= gamer2->getposX() - 9
            &&
            (this->getBolPosY() <= gamer2->getposY() + 30
             && this->getBolPosY() >= gamer2->getposY() - 30)
                ) {
            this->setDirectX(-this->getDirectX());
        }

        this->setBolPosX(this->getBolPosX() + this->getDirectX());


        if (this->getBolPosY() + this->getDirectY() < 500
            && this->getBolPosY() + this->getDirectY() > 0)
            this->setBolPosY(this->getBolPosY() + this->getDirectY());
        else {
            this->setDirectY(-this->getDirectY());
            this->setBolPosY(this->getBolPosY() + this->getDirectY());
        }

    }
};

#endif //PONG_PONG_H
