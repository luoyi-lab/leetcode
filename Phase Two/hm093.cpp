/*2.5 引用的本质
本质：引用的本质在C++内部是一个指针常量   指针常量：指针本身是常量，也就是这个指针变量保存的地址不能改，即指针本身不可以改，但它指向的内容可以改
                                       常量指针：指向的内容不能通过它改，指针本身可改
*/
#include <iostream>
using namespace std;

//发现是引用，转换为 int* const ref = &a;
void func(int& ref)
{
    ref = 100;//ref是引用，转换为*ref = 100
}

int main()
{
    int a = 10;

    //自动转换为 int* const ref = &a; 这里的&是地址的意思，指针常量是指指针指向的地址不可改，也说明为什么引用不可更改，即b不能又是a的别名，又是c的别名
    int& ref = a;
    ref = 20;//内部发现ref是引用，自动帮我们转换为：*ref = 20;  即指针指向的内容是可以改的

    cout << "a:" << a <<endl;
    cout << "ref:" << ref << endl;

    func(a);
    cout << "ref:" << ref << endl;
    return 0;
}