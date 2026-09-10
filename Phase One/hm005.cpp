/*1.4 常量 记录程序中不可更改的数据
1.#define 宏常量 #define 常量名 常量值
  一般位于文件上方，表示一个常量
2.const 修饰的变量 const 数据类型 常量名 = 常量值
  在变量定义前加const，修饰该变量为常量，不可更改，通俗数学角度来讲，就是把一个字母代表的值定下来
*/

#include<iostream>
using namespace std;
#define W 7 //宏常量一般位于文件上方
int main()
{
    cout <<"一周有：" << W << "天" << endl;

    //int month = 11; 这一行不可存在，因为重复定义了month
    const int month = 12;

    cout <<"一年有多少个月："<< month <<"个"<<endl;

    return 0;
}