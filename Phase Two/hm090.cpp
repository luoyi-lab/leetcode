/*2.2 引用注意事项
  引用必须初始化    int &b;这是错误的，引用上来就必须告知是谁的别名
  引用在初始化后，不可以改变
  int a = 10;
  int c = 20;
  int &b = a;
  int &b = c;   错误操作
  
*/
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int c = 20;
    int &b = a; //前面必须已经有a了
    cout << "a = " << a <<endl;
    b = 30;
    cout << "b = " << b <<endl;//其实就是同一个东西了现在
    cout << "a = " << a <<endl;
    
    /*int &b = c;
    cout << "b = " << b <<endl;      错误代码
    */
    b = c;//这是可以的，这是赋值操作，而不是更改引用
    cout << "b = " << b <<endl;
    cout << "a = " << a <<endl;

    return 0;
}