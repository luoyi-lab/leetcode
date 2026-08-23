/*4.2 循环结构 
4.2.1 while循环语句 满足循环条件，执行循环语句，语法如下：
while(循环条件)
{
  循环语句
}
只要循环条件的结果为真，就执行循环语句
*/
#include <iostream>
using namespace std;
int main()
{
    //打印0-9十个数字
    int num = 0;
    while (num <= 9)// 括号里条件为真则一直循环，一定要避免无限循环，要有退出循环的出口
    {
        cout << num <<endl;
        num++;
    }
    return 0;
}