#include "winsys.h"
#include "snake.h"

int main()
{
    Desktop desktop;
    desktop.insert(new InputLine(Rect(Point(5, 7), Point(25, 15))));
    desktop.insert(new Window(Rect(Point(2, 3), Point(30, 15)), '#'));
    desktop.insert(new Snake(Rect(Point(5, 5), Point(55, 20))));
    desktop.run();
    return 0;
}
