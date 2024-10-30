#ifndef SNAKE_WINSYS_H
#define SNAKE_WINSYS_H

#include "cpoint.h"
#include <vector>
#include <iostream>

using namespace std;

class CustomView
{
protected:
    CRect customGeom;

public:
    CustomView(CRect g) : customGeom(g) {}
    virtual ~CustomView() {}

    virtual void display() = 0;
    virtual bool handleUserInput(int key) = 0;
    virtual void moveView(const CPoint & delta);
};

class FancyWindow: public CustomView
{
protected:
    char symbol;
public:
    FancyWindow(CRect rect, char _symbol = '*') : CustomView(rect), symbol(_symbol) {}

    void display();
    bool handleUserInput(int key);
};

class DecoratedWindow: public FancyWindow
{
public:
    DecoratedWindow(CRect rect, char _symbol = '\'') : FancyWindow(rect, _symbol) {}

    void display();
};

class InputBox: public DecoratedWindow
{
    string inputText;
public:
    InputBox(CRect rect, char _symbol = ',') : DecoratedWindow(rect, _symbol) {}

    void display();
    bool handleUserInput(int key);
};

class ViewGroup: public CustomView
{
    vector< CustomView * > childViews;
public:
    ViewGroup(CRect g) : CustomView(g) {}
    ~ViewGroup();

    void display();
    bool handleUserInput(int key);
    void insertView(CustomView * view);
};

class DesktopEnvironment: public ViewGroup
{
public:
    DesktopEnvironment();
    ~DesktopEnvironment();

    void display();
    int fetchUserInput();
    void execute();
};

#endif //SNAKE_WINSYS_H
