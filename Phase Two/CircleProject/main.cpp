#include <iostream>
#include "Circle.h"
#include "Point.h"
using namespace std;

void isInCircle( Circle &c,  Point &p)
{
    int dx = c.getCenter().getX() - p.getX();
    int dy = c.getCenter().getY() - p.getY();
    int distance = dx * dx + dy * dy;
    int Rdistance = c.getR() * c.getR();

    if (distance == Rdistance)
        cout << "点在圆上" << endl;
    else if (distance > Rdistance)
        cout << "点在圆外" << endl;
    else
        cout << "点在圆内" << endl;
}

int main()
{
    Point center;
    center.setX(10);
    center.setY(0);

    Point p1;
    p1.setX(10);
    p1.setY(9);

    Circle c;
    c.setR(10);
    c.setCenter(center);

    isInCircle(c, p1);

    return 0;
}