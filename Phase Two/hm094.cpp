/*2.6 常量引用
作用：常量引用主要用来修饰形参，防止误操作

在函数形参列表中，可以加const修饰形参，防止形参改变实参
*/
#include <iostream>
using namespace std;

//打印数据的函数
void showValue(const int & val)//它是一个 int 的引用,引用可以理解成“变量的别名”，故main中直接是showValue(a);
{
    //val = 1000;  有了const，就可以防止这种重新赋值的误操作
    cout << "val = " << val <<endl;

}

int main()
{
    const int & ref = 10;//加上const之后 编译器将代码修改为 int temp = 10; int & ref = temp; 这成了一个合格的语法
    //ref = 20;这就不行了，因为没有原始的合法内存空间，你没法去修改。也即，加入const之后，变为只读，不可修改

    int a = 100;
    showValue(a);
    cout << "a = " << a <<endl;
    return 0;
}