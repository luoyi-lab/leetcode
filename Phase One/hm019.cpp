/*3.2 赋值运算符 用于将表达式的值赋给变量 具体如下：
运算符      术语        示例             结果
=          赋值       a=2;b=3          a=2;b=3
+=         加等于     a=0;a+=2           a=2
-=         减等于     a=2;a-=2           a=0
*=         乘等于     a=2;a*=2           a=4
/=         除等于     a=4;a/=2           a=2
%=         模等于     a=3;a%=2           a=1
*/
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    a = 20;
    cout << "a=" << a <<endl;
    a += 10;
    cout << "a=" << a <<endl;
    a -= 2;
    cout << "a=" << a <<endl;
    a *= 2;
    cout << "a=" << a <<endl;
    a /= 4;
    cout << "a=" << a <<endl;
    a %= 6;
    cout << "a=" << a <<endl;
    return 0;
}