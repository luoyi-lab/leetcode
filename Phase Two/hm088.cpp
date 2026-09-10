/* 1.3 new操作符
利用new操作符在堆区开辟数据
堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
语法：new 数据类型
利用new创建的数据，会返回该数据对应的类型的指针
*/
#include <iostream>
using namespace std;

//1.new的基本语法
int * func()
{
    //在堆区创建一个整型的数据
    int * p = new int(10);//new返回该数据对应的类型的指针，故前面用int * p
    return p;//这个p的内存被释放了，*p对应的堆区的内存没有被释放
}

void test01()
{
    int * p = func();
    cout << *p <<endl;
    cout << *p <<endl;
    //堆区的数据由程序员开辟和释放 用delete释放
    delete p;//这个p就是堆区数据的地址
    //cout << *p <<endl; 内存已经被释放了，此时无法再输出*p
}

//2.在堆区利用nem开辟数组
void test02()
{
    //创建10个整型的数组，在堆区
    int * arr = new int[10];//10代表数组里有10个元素   返回该数组的首地址

    for(int i = 0 ; i < 10 ; i++)
    {
        arr[i] = i + 100;//给10个元素赋值，即100-109
    }

    for(int i = 0 ; i < 10 ; i++)
    {
        cout << arr[i] <<endl;//给10个元素赋值，即100-109
    }

    delete [] arr;  // 释放堆区数组，要加[]，告诉编译器我释放的是数组
    arr = nullptr; // 避免悬空指针
}

int main()
{
    test01();
    test02();
    return 0;
}