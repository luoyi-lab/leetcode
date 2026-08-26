/*6.4 值传递
所谓值传递，就是函数调用时实参将数值传入给形参
值传递时，如果形参发生了任何的改变，并不会影响实参             这东西其实很简单，数学上讲：一个函数，一堆字母没有意义，要带入数值才算出来结果从而有意义，数值和字母之间没有任何关系
*/
#include <iostream>
using namespace std;

//定义函数，实现两个数字进行交换函数
//如果函数不需要返回值，声明的时候可以写void
void swap (int num1, int num2)
{
    cout << "交换前：" <<endl;
    cout << "num1 = " << num1 <<endl;
    cout << "num2 = " << num2 <<endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：" <<endl;
    cout << "num1 = " << num1 <<endl;
    cout << "num2 = " << num2 <<endl;


    //return; 返回值不需要的时候，可以不写return
}

int main()
{
    int a = 10;
    int b = 20;
    cout << "a=" << a <<endl;
    cout << "b=" << b <<endl;
    //值传递时，如果形参发生了任何的改变，并不会影响实参 
    /*
    主函数 main
    定义局部变量 a = 10，b = 20，并输出它们的初始值。
    调用 swap(a, b)：
    实参 a 和 b 的 值（10 和 20）被复制给形参 num1 和 num2。           仅仅是值复制给了形参，从始至终a和b都没有发生改变，本质上a b 和 num1 num2还是不同的东西，内存地址都不同
    在 swap 内部，交换的是形参的副本，完全不涉及外部的 a 和 b。
    调用结束后，再次输出 a 和 b，会发现它们 没有改变，仍然是 10 和 20。

    核心知识点：值传递
    形参是实参的副本，函数内对形参的任何修改，都只影响副本，不会影响原始变量。
    这就是为什么即使 swap 内部成功交换了 num1 和 num2，外部的 a 和 b 依然保持原样。
    */
    swap(a,b);//这里不需要cout的原因是函数内部已经有输出了
    cout << "a=" << a <<endl;
    cout << "b=" << b <<endl;//可以看到a和b的数值没有发生变化
    return 0;
}