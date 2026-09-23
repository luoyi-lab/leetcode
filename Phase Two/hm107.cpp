/*4.2.2 构造函数的分类及调用
两种分类方式：
  按参数分为：有参构造和无参构造（默认构造）
  按类型分为：普通构造与拷贝构造
三种调用方式：
  括号法
  显示法
  隐式转换法 
*/
#include <iostream>
using namespace std;

class Person //构造函数和析构函数必须作为类的成员函数来声明,它们是对象生命周期的一部分
{
public:
    //构造函数 普通构造函数
    Person()//无参构造
    {
        cout << "Person的无参构造函数调用" <<endl;
    }
    Person(int a)//有参构造
    {
        age = a;
        cout << "Person的有参构造函数调用" <<endl;
    }

    //拷贝构造函数
    Person( const Person &p )//把这个Person p 完全复制过来 const是限定 p 不能乱改了
    {
        //将传入的人身上的所有属性，拷贝到我身上
        age = p.age;
        cout << "Person的拷贝构造函数调用" <<endl;

    }

    ~Person()
    {
        cout << "Person的析构函数调用" <<endl;
    }

    int age;
};

//调用
void test01()
{
    //1.括号法（其实是最常用的）
    //Person p1;//默认构造函数调用
    //Person p2(10);//有参构造函数调用
    //Person p3(p2);//拷贝构造函数调用

    //cout << "p2的年龄为：" << p2.age <<endl;
    //cout << "p3的年龄为：" << p3.age <<endl;//实现拷贝功能

    //注意事项1
    //调用默认构造函数的时候，不要加()
    //因为这行代码： Person(); 编译器会认为是一个函数的声明，不会认为在创建对象

    //2.显示法
    Person p1;
    Person p2 = Person(10);//有参构造  等号的右侧是匿名对象：特点是当前行执行结束后，系统会立即回收掉匿名对象（一定是当前行结束，而不是整个函数或程序结束）
    Person p3 = Person(p2);//拷贝构造

    //注意事项2
    //不要利用拷贝构造函数 初始化匿名对象：即Person(p3); 因为编译器会认为 Person(p3) == Person p3 这是一个默认无参构造，与Person p3 = Person(p2); 冲突。这是一个对象声明

    //3.隐式转换法
    Person p4 = 10;//相当于写了Person p4 = Person(10); 有参构造
    Person p5 = p4;//拷贝构造

}

int main()
{
    test01();
    return 0;
}