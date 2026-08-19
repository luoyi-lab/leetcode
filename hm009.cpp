/*2.2 sizeof关键字 利用sizeof关键字可以统计数据类型所占的内存大小
语法： sizeof( 数据类型或变量 )
*/
#include <iostream>
using namespace std;
int main()
{
   long A = 18;
   int b = 12;
   short c =22;
   cout << "A+b-c=" << A + b - c <<endl;
   cout << "A所占字节为" << sizeof( A ) <<endl;
   cout << "short类型所占字节为" << sizeof( short ) <<endl;
    return 0;
}