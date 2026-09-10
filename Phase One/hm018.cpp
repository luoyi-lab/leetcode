/*3.1 算术运算符 递增递减
++ 前置递增      例子：a=2;b=++a     a=3;b=3 
++ 后置递增      例子：a=2;b=a++     a=3;b=2
-- 前置递减      例子：a=2;b=--a     a=1;b=1
-- 后置递减      例子：a=2;b=a--     a=1;b=2
*/
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    ++a ;//让变量加1
    cout << "a=" << a <<endl; 
    int b = 10;
    b++;//看起来还是让变量加1了
    cout << "b=" << b <<endl; 
    //前置递增 先让变量+1 然后再进行表达式运算
    int a2 = 10;
    int b2 = ++a2 * 10;
    cout << "a2=" << a2 <<endl; 
    cout << "b2=" << b2 <<endl; 
    //后置递增 先进行表达式的运算 然后让变量+1
    int a3 = 10;
    int b3 = a3++ * 10;
    cout << "a3=" << a3 <<endl; 
    cout << "b3=" << b3 <<endl;//先进行表达式的运算 所以b3=10*10=100 再让变量+1： a3 = 10+1 = 11
    
    //递减运算和递增运算逻辑完全一致，只是+1变成-1
    int a4 = 10;
    int b4 = --a4 * 10;
    cout << "a4=" << a4 <<endl; 
    cout << "b4=" << b4 <<endl; 
    int a5 = 10;
    int b5 = a5-- * 10;
    cout << "a5=" << a5 <<endl; 
    cout << "b5=" << b5 <<endl;
    return 0;
}