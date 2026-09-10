/*1.1 程序运行前
在程序编译后（翻译为电脑看得懂的二进制语言），生成了可执行程序，还未执行该程序前分为两个区域
代码区：
  存放CPU执行的机器指令（就是我写的代码）
  代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
  代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令
全局区：
  全局变量和静态变量存放在此
  全局区还包含了常量区，字符串常量和其他常量（const修饰的全局变量）也存放在此
  该区域的数据在程序结束后由操作系统释放
*/
#include <iostream>
using namespace std;

//全局变量 不在函数体中的变量
int g_a = 10;
int g_b = 11;

////const修饰的全局变量，称全局常量
const int c_g_a = 10;//c：const   g：globl 全局   l：local 局部
const int c_g_b = 10;


int main()
{
    //创建普通局部变量
    int a = 10;//写在函数体内的变量都叫局部变量
    int b = 11;

    cout << "局部变量a的地址为：" << &a <<endl;
    cout << "局部变量b的地址为：" << &b <<endl;

    cout << "全局变量g_a的地址为：" << &g_a <<endl;
    cout << "全局变量g_b的地址为：" << &g_b <<endl;

    //静态变量 在普通变量前面加static，属于静态变量
    static int s_a = 10;
    static int s_b = 11;

    cout << "静态变量s_a的地址为：" << &s_a <<endl;
    cout << "静态变量s_b的地址为：" << &s_b <<endl;//明显的看到静态变量的内存地址在全局区

    //常量 分两种：1.字符串常量 2.const修饰的变量
    //字符串常量（双引号括起来的）
    "hello word";
    cout << "字符串常量的地址为：" << &"hello word" <<endl;//明显的看到内存地址在全局区

    //const修饰的变量 分两种：1.const修饰的全局变量 2.const修饰的局部变量
    //const修饰的全局变量，称全局常量
    cout << "const修饰的全局变量，称全局常量的地址为：" << &c_g_a <<endl;
    cout << "const修饰的全局变量，称全局常量的地址为：" << &c_g_b <<endl;

    //const修饰的局部变量
    const int c_l_a = 10;//c：const   g：globl 全局   l：local 局部
    const int c_l_b = 11;
    cout << "const修饰的局部变量，称局部常量的地址为：" << &c_l_a <<endl;//明显看到不在全局区，和普通局部变量在一起
    cout << "const修饰的局部变量，称局部常量的地址为：" << &c_l_b <<endl;

    return 0;
}