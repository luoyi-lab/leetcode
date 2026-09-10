// 函数 函数的分文件编写
#include "swap.h"

// 函数的定义（实现）
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "a = " << a << ", b = " << b << endl;
}
