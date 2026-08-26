/*6.6 函数的声明 
作用：告诉编译器函数名称以及如何调用函数，函数的实际主体可以单独定义
函数的声明可以有多次，但是函数的定义只能有一次
*/
#include <iostream>
using namespace std;
//提前告诉编译器函数的存在，可以利用函数的声明，声明之后，函数可以放在int main后面的位置，否则只能写在前面
//声明可以写多次，但是定义只能写一次

int max(int a , int b);

int main()
{
    int a = 60;
    int b = 20;
    int c = max(a,b);
    cout << c <<endl;

    return 0;
}

int max (int x , int y)//比较函数，实现两个整型数字进行比较，并且返回较大的值
{
    return x > y ? x : y; //三目运算符：x > y成立则返回x，否则就返回y
}