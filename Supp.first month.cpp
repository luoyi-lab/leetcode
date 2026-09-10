/*1. 类（Class）
类是 C++ 面向对象编程的核心，它允许我们将数据（成员变量）和操作这些数据的函数（成员函数）封装在一起。通过类，我们可以创建具有特定属性和行为的对象，类本身是零内存占用
关键特性（构成）：
  成员变量：描述对象的状态
  成员函数：定义对象的行为，可以访问和修改成员变量
  访问修饰符：
  public：成员可以被外部访问。
  private：成员只能被类内部访问（默认）。
  protected：成员可被派生类访问。 即：本类内部可以访问，儿子（派生类）内部也可以访问
  构造函数：在对象创建时自动调用，用于初始化成员变量。
  析构函数：在对象销毁时自动调用，用于释放资源。
*/
//示例：定义一个 Person 类
#include <iostream>
#include <string>
using namespace std;

class Person 
{
private:
    string name;   // 姓名
    int age;       // 年龄

public:
    // 构造函数（带默认参数）
    Person(string n = "Unknown", int a = 0) : name(n), age(a) //name(n) 的意思是：调用成员变量 name 的拷贝构造函数，用参数 n 的值直接构造出 name。
    {
        cout << "Person 构造: " << name << endl;
    }

    // 析构函数
    ~Person() 
    {
        cout << "Person 析构: " << name << endl;
    }

    // 成员函数：设置信息
    void setInfo(string n, int a) 
    {
        name = n;
        age = a;
    }

    // 成员函数：打印信息
    void print() const 
    {
        cout << "姓名: " << name << ", 年龄: " << age << endl;
    }
};

int main() 
{
    Person p1("张三", 25);
    p1.print();

    Person p2;
    p2.setInfo("李四", 30);
    p2.print();

    return 0;
}
