/*3.1 算术运算符 取模 取余运算
%  10%3=1
除数还是不能为0
两个小数不能取模
*/
#include <iostream>
using namespace std;
int main()
{
    int a1 = 10;
    int b1 = 3;
    float a2 = 1.2f;
    float b2 = 2.5f;
    cout << a1%b1 <<endl;
    //cout << b2%a2 <<endl; 此行无效 取余运算只能是两个整数运算
    //cout << a1%a2 <<endl; 取余运算只能是两个整数运算
    return 0;
}