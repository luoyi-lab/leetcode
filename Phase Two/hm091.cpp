/*2.3 引用做函数参数
作用：函数传参时，可以利用引用的技术让形参修饰实参   （回顾：参数传递方式：1.值传递 2.地址传递）
优点：可以简化指针修改实参
*/
#include <iostream>
using namespace std;

//实现一个交换函数

//1.值传递
void mySwap01(int a , int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "swap01 a = " << a <<endl;
    cout << "swap01 b = " << b <<endl;
}

//2.地址传递
void mySwap02(int* a , int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "swap02a地址 = " << a <<endl;
    cout << "swap02b地址 = " << b <<endl;

    cout << "swap02 a = " << *a <<endl;
    cout << "swap02 b = " << *b <<endl;
}

//3.引用传递
void mySwap03(int &a , int &b)//这里的a其实是原来a的别名，只是别名和原名一样，见hm089，这就解释了为什么引用传递后，实参也被改变了
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    mySwap01(a,b);
    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;//值传递，a和b的实参都没有发生变化

    mySwap02(&a,&b);
    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;//地址传递：形参修饰实参

    mySwap03(a,b);
    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;//引用传递：形参修饰实参

    return 0;
}