/*2.4 引用做函数返回值
作用：引用是可以作为函数的返回值存在的
注意：不要返回局部变量引用
用法：函数调用作为左值
*/
#include <iostream>
using namespace std;

//1.不要返回局部变量的引用
int& test01()
{
    int a = 10;//局部变量 存放在四区中的栈区
    return a; //错误写法，局部变量已经被释放了，不能返回这个a
}

//2.函数的调用可以作为左值
int& test02()//函数返回类型是“int 的引用”   引用可以理解为变量的别名。
{
    static int a = 10;//静态变量，存放在全局区，在程序结束后由系统释放
    return a;//因为返回类型是 int&，所以这里不是把 a 的值复制一份返回，而是返回 a 这个变量本身的别名
}

int main()
{
    /*int &ref = test01();          按道理ref = a ，但局部变量a已经被释放了
    cout << "ref = " << ref <<endl;
    */

    int &ref2 = test02();          
    cout << "ref2 = " << ref2 <<endl;
    cout << "ref2 = " << ref2 <<endl;

    test02() = 1000;//函数作为左值，函数的返回是一个引用，test02() 这个表达式就相当于 a，所以可以放在赋值号左边，相当于做了一个a = 1000的操作

    cout << "ref2 = " << ref2 <<endl;
    cout << "ref2 = " << ref2 <<endl;
}