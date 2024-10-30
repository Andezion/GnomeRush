#ifndef SNAKE_CPOINT_H
#define SNAKE_CPOINT_H

#include <list>

using namespace std;

struct Point
{
    int x;
    int y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {};
    Point& operator+=(const Point& delta)
    {
        x += delta.x;
        y += delta.y;
        return *this;
    }

    bool operator==(const Point& other) const
    {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Point& other) const
    {
        return !(*this == other);
    }
};

struct Rect
{
    Point topleft;
    Point size;
    Rect(Point t1 = Point(), Point s = Point()) : topleft(t1), size(s) {};
};


#endif //SNAKE_CPOINT_H
