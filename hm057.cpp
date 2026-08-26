/*7.3 指针所占内存空间
提问：指针也是种数据类型，那么这种数据类型占用多少内存空间？    根据上所学，知道指针存的是一个数据的地址：0x0000
答：在32位操作系统下占用4个字节空间，在64位操作系统下占用8个字节空间
*/
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int * p = &a;
    cout << sizeof(p) <<endl;
    cout << sizeof(int *) <<endl;//int * 是一种数据类型
    cout << sizeof(float *) <<endl;
    cout << sizeof(double *) <<endl;
    cout << sizeof(char *) <<endl;
    
    return 0;
}
