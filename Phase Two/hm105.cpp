/*练习案例2：点和圆的关系
设计一个圆类（Circle）,和一个点类（Point），计算点和圆的关系
  点在圆内
  点在圆上
  点在圆外
  点到圆心的距离和半径比较

  点到圆心的距离：勾股定理
*/
#include <iostream>
using namespace std;
#include <string>

//点类
class Point 
{ 
public:
    //设置X坐标
    void setX(int x)
    {
        m_X = x;
    }
    //获取X坐标
    int getX()
    {
        return m_X;
    }

    //设置Y坐标
    void setY(int y)
    {
        m_Y = y;
    }
    //获取Y坐标
    int getY()
    {
        return m_Y;
    }

private:
    int m_X;
    int m_Y;
};

//圆类
class Circle
{
public:
    //设置半径
    void setR(int r)
    {
        m_R = r;
    }

    //获取半径
    int getR()
    {
        return m_R;
    }

    //设置圆心
    void setCenter(Point center)//要传入上面设置的点类进来
    {
        m_Center = center;
    }

    //获取圆心
    Point getCenter()
    {
        return m_Center;
    }

private:
    int m_R;//半径
    Point m_Center;//圆心  这是案例核心，在类中，可以让另一个类，作为本类成员
};

//判断点和圆的关系函数
void isInCircle(Circle &c , Point &p)
{
    //计算两点之间距离的平方
    int distance = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) +
                   (c.getCenter().getY() - p.getY())*(c.getCenter().getY() - p.getY());

    //计算半径的平方
    int Rdistance = c.getR()*c.getR();

    //判断关系
    if (distance == Rdistance)
    {
        cout << "点在圆上" <<endl;
    }
    else if (distance > Rdistance)
    {
        cout << "点在圆外" <<endl;
    }
    else
    {
    cout << "点在圆内" <<endl;
    }
}

int main()
{
    Point center;//center是圆心 
    center.setX(10);
    center.setY(0);

    Point p1;
    p1.setX(10);//p1在圆内
    p1.setY(9);

    Point p2;
    p2.setX(10);//p2在圆上
    p2.setY(10);

    Point p3;
    p3.setX(10);//p3在圆外
    p3.setY(11);
    
    //创建一个圆
    Circle c;
    c.setR(10);
    c.setCenter(center);

    //判断关系
    isInCircle(c , p1);
    isInCircle(c , p2);
    isInCircle(c , p3);

    return 0;
}