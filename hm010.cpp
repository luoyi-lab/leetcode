/*2.3 实型（浮点型） 用来表示小数 分两类如下：
1.单精度 float  4字节  7位有效数字
2.双精度 double  8字节  15~16位有效数字
默认情况下输出一个小数会显示出6位有效数字
*/
#include <iostream>
using namespace std;
int main()
{
   float A = 18.778f;//加一个f 告诉电脑这是一个单精度类型数据，不加f默认为双精度
   double d = 12.669;
   cout << "A=" << A << endl;
   cout << "A+d=" << A + d << endl;
   cout << "A所占字节为" << sizeof( A ) << endl;
   cout << "double类型所占字节为" << sizeof( double ) << endl;
   //科学计数法
   float f1 = 3.2e3;//3.2*10^3
   float f2 = 3.2e-1;//3.2*10^-1
   cout << "f1=" << f1 << endl;
   cout << "f2=" << f2 << endl;
   return 0;
}