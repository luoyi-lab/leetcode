/*3.3.2 函数重载注意事项
  引用作为重载条件
  函数重载碰到函数默认参数
*/
#include <iostream>
using namespace std;

//函数重载的注意事项
//1.引用作为重载的条件
void func(int &a)
{
    cout << "func(int &a)的调用" <<endl;
}

void func(const int &a)//和int &a相比属于类型不同
{
    cout << "func(const int &a)的调用" <<endl;
}

//2.函数重载碰到默认参数
void func2(int a , int b = 10)
{
    cout << "func2(int a)的调用" <<endl;
}

void func2(int a)
{
    cout << "func2(int a)的调用" <<endl;
}

int main()
{
    int a = 10;
    func(a);//会跑void func(int &a)，因为a是一个变量，第二个const是限制a为只读状态，不可写
    func(10);//会跑void func(const int &a)，因为10为只读状态，不可写。而且为什么不跑void func(int &a)，因为int &a = 10,这是错误代码，没有合法的内存地址空间。而const int &a = 10，合法
    
    //func2(12); 此时func2上下两个都可以调用，错误，要避免这种情况
    func2(13,14);//此时只能调用第一个函数
    return 0;
}