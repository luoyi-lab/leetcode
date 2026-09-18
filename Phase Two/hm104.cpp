/*练习案例1：设计长方体类
设计长方体类(Cube)
求出长方体的面积和体积
分别用全局函数和成员函数判断两个长方体是否相同
*/
#include <iostream>
using namespace std;
#include <string>

//长方体设计案例
//1.创建长方体类
//2.设计属性：m_L m_W m_H
//3.设计行为：获取面积和体积
//4.判断两个长方体是否相等(分别利用全局函数和成员函数)
class Cube
{
public:
    //设置长
    void setL(int l)
    {
        m_L = l;
    }
    //获取长
    int getL()
    {
        return m_L;
    }

    //设置宽
    void setW(int w)
    {
        m_W = w;
    }
    //获取宽
    int getW()
    {
        return m_W;
    }

    //设置高
    void setH(int h)
    {
        m_H = h;
    }
    //获取高
    int getH()
    {
        return m_H;
    }
    
    //获取面积
    int calculateS()
    {
        return 2*m_L*m_W + 2*m_L*m_H + 2*m_W*m_H;
    }

    //获取体积
    int calculateV()
    {
        return m_L*m_W*m_H;
    }

    //利用成员函数来判断两个长方体是否相等
    bool isSameByClass(Cube &c)//c1 调用自己的 isSameByClass 函数，问：“我和 c 相等吗？”
    {
        if(m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
        {
        return true;
        }

        return false;
    }
     
    

private://属性最好放在私有权限里面
    int m_L;//长
    int m_W;//宽
    int m_H;//高
};

//利用全局函数来判断两个长方体是否相等  全局函数类似于局外人，需要输入两个参数 成员函数中，c1已经存在了，只要再拿一个来和它对比就行
bool isSame(Cube &c1 , Cube &c2)//通过引用的方式传递数据
{
    if(c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
    {
        return true;
    }

    return false;
}

int main()
{
    //创建立方体对象
    Cube c1;
    c1.setL(10);
    c1.setW(20);
    c1.setH(15);
    cout << "长：" << c1.getL() << " 宽：" << c1.getW() << " 高：" << c1.getH() <<endl;
    cout << "c1的面积为：" << c1.calculateS() <<endl;
    cout << "c1的体积为：" << c1.calculateV() <<endl;

    //创建第二个立方体
    Cube c2;
    c2.setL(10);
    c2.setW(20);
    c2.setH(15);

    bool ret = isSame(c1,c2);
    if(ret)//意思是如果ret是一个真值
    {
        cout << "全局函数判断：c1和c2是相等的" <<endl;
    }
    else
    {
        cout << "全局函数判断：c1和c2是不相等的" <<endl;
    }

    ret = c1.isSameByClass(c2);//c1 调用自己的 isSameByClass 函数，问：“我和 c2 相等吗？”
    
    bool ret1 = c1.isSameByClass(c2);
    if(ret1)//意思是如果ret是一个真值
    {
        cout << "成员函数判断：c1和c2是相等的" <<endl;
    }
    else
    {
        cout << "成员函数判断：c1和c2是不相等的" <<endl;
    }

    return 0;
}