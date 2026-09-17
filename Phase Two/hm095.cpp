/*3 函数提高
3.1 函数默认参数
C++中，函数的形参列表中的形参是可以有默认值的
语法：返回值类型 函数名 (参数 = 默认值)
{
}
*/ 
#include <iostream>
using namespace std;

int func(int a , int b = 20 , int c = 30)
{
    return a + b + c;

}

//注意事项
//1.如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值 即不能类似于：int func(int a = 10 , int b , int c = 30)
//2.如果函数声明（没有大括号的）有默认参数，函数实现（有大括号的）就不能有默认参数，声明和实现只能有一个有默认参数
int func2(int a = 10 , int b = 20);//这是函数声明

int func2(int a , int b)//这是函数实现，有了声明，函数的实现就可以放在任意位置了
{
    return a + b;
}


int main()
{
    cout << func(10) <<endl;//可以只传入一个参数
    cout << func(10,30) <<endl;//多传也可以，并且用我传入的这个值
    cout << func2(15,16) <<endl;

    return 0;
}