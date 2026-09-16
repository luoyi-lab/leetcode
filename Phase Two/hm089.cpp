/*2 引用 
2.2 引用的基本使用
作用：给变量起别名
语法：数据类型 &别名 = 原名
*/
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &b = a; 
    cout << "a = " << a <<endl;
    b = 30;
    cout << "b = " << b <<endl;//其实就是同一个东西了现在
    cout << "a = " << a <<endl;
    return 0;
}