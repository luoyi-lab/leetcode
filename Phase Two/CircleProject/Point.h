//头文件里只放声明，不写具体实现
#pragma once   // 防止头文件被重复包含

class Point
{
public:
    void setX(int x);
    int getX(); 

    void setY(int y);
    int getY();

private:
    int m_X;
    int m_Y;
};
