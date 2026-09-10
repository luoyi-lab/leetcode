/*1.2 程序运行后
  堆区：
    由程序员分配释放，若程序员不释放，程序结束后由操作系统回收（程序运行期间，由程序员决定生死，程序结束之后，若还未释放，系统自动释放）
    在C++中主要利用new在堆区开辟内存
*/
#include <iostream>
using namespace std;

int * func()
{
    //利用new关键字，将数据开辟到堆区

    //指针本质上也是局部变量，放在栈区，但指针保存的数据是放在堆区的
    int * p = new int (10);
    return p;//返回的是p中保存的值，也就是堆区地址。注意：不是返回p自己的地址（&p），而是返回p指向的堆区地址。这就是为什么没有被释放掉的原因
}

int main()
{
    int * k = func();
    cout << *k <<endl;
    cout << *k <<endl;

    delete k;   // 释放堆区内存
    k = nullptr; // 避免悬空指针

    return 0;
}