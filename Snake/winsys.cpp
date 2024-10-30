#include <vector>
#include <iostream>
#include <cctype>
#include <cstdarg>

#include "winsys.h"
#include "cpoint.h"
#include "screen.h"

using namespace std;

void CustomView::moveView(const CPoint & delta)
{
    customGeom.topleft += delta;
}

void FancyWindow::display()
{
    for (int y = customGeom.topleft.y; y < customGeom.topleft.y + customGeom.size.y; y++)
        for (int x = customGeom.topleft.x; x < customGeom.topleft.x + customGeom.size.x; x++)
        {
            gotoyx(y, x);
            printl("%c", symbol);
        }
}

bool FancyWindow::handleUserInput(int key)
{
    switch (key)
    {
        case KEY_UP:
            moveView(CPoint(0, -1));
            return true;
        case KEY_DOWN:
            moveView(CPoint(0, 1));
            return true;
        case KEY_RIGHT:
            moveView(CPoint(1, 0));
            return true;
        case KEY_LEFT:
            moveView(CPoint(-1, 0));
            return true;
    };
    return false;
}

void DecoratedWindow::display()
{
    for(int y = customGeom.topleft.y; y < customGeom.topleft.y + customGeom.size.y; y++)
    {
        if((y == customGeom.topleft.y) || (y == customGeom.topleft.y + customGeom.size.y-1))
        {
            for(int x = customGeom.topleft.x; x < customGeom.topleft.x + customGeom.size.x; x++)
            {
                gotoyx(y, x);
                if((x == customGeom.topleft.x) || (x == customGeom.topleft.x + customGeom.size.x-1))
                    printl ("+");
                else
                    printl ("-");
            }
        }
        else
        {
            for(int x = customGeom.topleft.x; x < customGeom.topleft.x + customGeom.size.x; x++)
            {
                gotoyx(y, x);
                if((x == customGeom.topleft.x) || (x == customGeom.topleft.x + customGeom.size.x-1))
                    printl ("|");
                else
                    printl ("%c", symbol);
            }
        }
    }
}

void InputBox::display()
{
    DecoratedWindow::display();

    unsigned int row = 0;
    for(int y = customGeom.topleft.y+1; y < customGeom.topleft.y + customGeom.size.y-1; y++, row++)
    {
        unsigned int letter = row * (customGeom.size.x-2);
        for (int x = customGeom.topleft.x+1; x < customGeom.topleft.x + customGeom.size.x-1; x++, letter++)
        {
            gotoyx(y, x);
            printl("%c", letter < text.size() ? text[letter] : symbol);
        }
    }
}

bool InputBox::handleUserInput(int c)
{
    if(DecoratedWindow::handleUserInput(c))
        return true;
    if((c == KEY_DC) || (c == KEY_BACKSPACE))
    {
        if (text.length() > 0)
        {
            text.erase (text.length() - 1);
            return true;
        };
    }
    if((c > 255) || (c < 0))
        return false;
    if(!isalnum (c) && (c != ' '))
        return false;
    text.push_back(c);
    return true;
}

void ViewGroup::display()
{
    for(int y= customGeom.topleft.y; y < customGeom.topleft.y + customGeom.size.y; y++)
    {
        gotoyx(y, customGeom.topleft.x);
        for(int x = 0; x < customGeom.size.x; x++)
            printl (".");
    }

    for (vector< CustomView * >::iterator i = childViews.begin(); i != childViews.end(); i++)
        (*i)->display();
}

bool ViewGroup::handleUserInput(int key)
{
    if (!childViews.empty() && childViews.back()->handleUserInput(key))
        return true;
    if (key == '\t')
    {
        if (!childViews.empty())
        {
            childViews.insert(childViews.begin(), childViews.back());
            childViews.pop_back();
        };
        return true;
    }
    return false;
}

void ViewGroup::insertView(CustomView * view)
{
    childViews.push_back(view);
}

ViewGroup::~ViewGroup()
{
    for (vector< CustomView * >::iterator i = childViews.begin();
         i != childViews.end(); i++)
        delete(*i);
}

DesktopEnvironment::DesktopEnvironment() : ViewGroup(CRect())
{
    init_screen();
    update_screen();
}

DesktopEnvironment::~DesktopEnvironment()
{
    done_screen();
}

void DesktopEnvironment::display()
{
    getscreensize (customGeom.size.y, customGeom.size.x);

    for(int y = customGeom.topleft.y; y < customGeom.topleft.y + customGeom.size.y; y++)
    {
        gotoyx(y, customGeom.topleft.x);
        for (int x = 0; x < customGeom.size.x; x++)
            printl (".");
    }

    ViewGroup::display();
}

int DesktopEnvironment::fetchUserInput()
{
    return ngetch();
}

void DesktopEnvironment::execute()
{
    update_screen();
    display();
    refresh();

    while(1)
    {
        int c = fetchUserInput();

        if(c == 'q' || c == 'Q')
            break;

        if(c == KEY_RESIZE || handleUserInput(c))
        {
            update_screen();
            display();
            refresh();
        }
    }
}


