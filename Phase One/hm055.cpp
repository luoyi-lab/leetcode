/*6.7 函数的分文件编写
作用：让代码结构更清晰  函数分文件编写一般有4个步骤，如下：
1.创建后缀名为.h的头文件
2.创建后缀名为.cpp的源文件
3.在头文件中写函数的声明
4.在源文件中写函数的定义
*/
#include <iostream>
using namespace std;
#include "swap.h"//标明头文件

void swap( int a , int b )//两个数字交换的函数
{
    int temp = a;
    a = b;
    b = temp;
    cout << "a=" << a <<endl;
    cout << "b=" << b <<endl;
}



int main()
{
    int a = 10;
    int b = 30;//注意这里的a和b和上面函数中的a和b不是同一个东西
    swap(a,b);
    return 0; 
}


/*正确的分文件写法（3个文件）
文件1：swap.h（头文件——只负责喊口号，即声明）
#pragma once  // 防止重复包含
#include <iostream>
using namespace std;
//这里只写函数的声明（告诉编译器：有个叫swap的函数存在）
void swap(int a, int b);

文件2：swap.cpp（源文件——负责干具体活，即定义）
#include "swap.h"
//这里写函数的定义（具体怎么交换）
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}

文件3：main.cpp（主逻辑——负责调用）
#include <iostream>
using namespace std;
#include "swap.h"  // 只需要包含头文件，就能使用swap函数

int main()
{
    int a = 10;
    int b = 30;
    swap(a, b);  // 调用
    return 0;
}

注意编译的时候要文件2和文件3一起编译
*/