/*6.3 函数的调用 使用定义好的函数
语法：函数名(参数)
*/
#include <iostream>
using namespace std;

int add( int num1 , int num2 )//这里的num1和num2没有实际数值，为形式参数，简称形参
{
    int sum = num1 * num2;
    return sum;
}

int main()
{
    int a =2;
    int b =3;//a和b此时有实际的值，简称实参
    int c = add(a,b);//将c赋值为函数的返回值sum
    cout << c <<endl;
    a = 100;
    b = 5;
    c = add(a,b);
    cout << c <<endl;
    return 0; 
}