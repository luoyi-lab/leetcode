/*2 数据类型
创建变量或常量等时，必须要指出相应的数据类型，否则无法分配内存，即占用的字节
2.1 整形 表示整数类型的数据 具体如下：
short 短整型   2字节    正负2的15次方
int 整型       4字节    正负2的31次方
long 长整型    4或8字节   正负2的31次方
long long 长长整型    8字节  正负2的63次方
以上四种的区别就是可取值的范围越来越广
*/
#include <iostream>
using namespace std;
int main()
{
   long A = 18;
   int b = 12;
   short c =22;
   cout << "A+b-c=" << A + b - c <<endl;
    return 0;
}