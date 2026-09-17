/*3.3 函数重载
3.3.1 函数重载概述
作用：函数名可以相同，提高复用性

函数重载满足条件：
  同一个作用域下
  函数名称相同
  函数参数类型不同，或个数不同，或顺序不同

注意：函数的返回值不可以作为函数重载的条件
*/
#include <iostream>
using namespace std;

//函数重载，可以让函数名相同

void func()
{
    cout << "func 的调用" <<endl;
}

void func(int a)
{
    cout << "func(int) 的调用" <<endl;
}

void func(double a)
{
    cout << "func(double) 的调用" <<endl;
}

void func(double a , int b)
{
    cout << "func(double , int) 的调用" <<endl;
}

void func(int a , double b)
{
    cout << "func(double , int) 的调用" <<endl;
}

//注意事项 函数的返回值不可以作为函数重载的条件

/*int func(int a , double b)
{
    cout << "func(double , int) 的调用" <<endl;
}
    简单来说，不可以只改返回值类型，别的完全相同，因为这样机器没法识别
*/

int main()
{
    func();
    func(10);
    double b = 3.14;
    func(b);
    func(3.14,10);
    func(10,3.14);

    return 0;
}