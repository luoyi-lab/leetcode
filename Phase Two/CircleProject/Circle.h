#pragma once
#include "Point.h"   // 因为 Circle 里用到了 Point

class Circle
{
public:
    void setR(int r);
    int getR() ;

    void setCenter(Point center);
    Point getCenter();

private:
    int m_R;
    Point m_Center;
};