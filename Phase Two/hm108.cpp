/*4.2.3 拷贝构造函数调用时机
C++中拷贝构造函数调用时机通常有三种情况
  1.使用一个已经创建完毕的对象来初始化一个新对象
  2.值传递的方式给函数参数传值
  3.以值方式返回局部对象
*/
#include <iostream>
using namespace std;

//1.使用一个已经创建完毕的对象来初始化一个新对象

//2.值传递的方式给函数参数传值

//3.以值方式返回局部对象

class Person
{
public:
    Person()
    {
        cout << "Person的默认构造函数调用" <<endl;
    }

    Person(int age)
    {
        cout << "Person的有参构造函数调用" <<endl;
        m_Age = age;
    }

    Person(const Person &p)//用“已经存在的同类型对象”来创建一个新对象
    {
        cout << "Person的拷贝构造函数调用" <<endl;
        m_Age = p.m_Age;
    }

    ~Person()
    {
        cout << "Person的析构函数调用" <<endl;
    }

    int m_Age;
};

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person p1(20);
    Person p2(p2);

    cout << "P2的年龄为：" << p2.m_Age <<endl;
}

//2.值传递的方式给函数参数传值
void dowork(Person p)//这个“用同类型对象初始化另一个对象”的过程，就会调用 拷贝构造函数
{

}

void test02()
{
    Person p;
    dowork(p);
}

//3.以值方式返回局部对象

Person dowork2()
{
    Person p1;
    return p1;
}

void test03()
{
    Person p = dowork2();

}


int main()
{
    //test01();
    //test02();
    test03();
    return 0;
}