/*4.2.3 for循环语句 满足循环条件，执行循环语句 语法如下：
for(起始表达式;条件表达式;末尾循环体)
{
  循环语句；
}

*/
#include <iostream>
using namespace std;
int main()
{
    
    for(int num = 0 ; num < 10 ; num++ )
    {
        cout << num <<endl;
    }
    return 0;
}

/*逻顺序如下：
for = 对于 （每一次）
int num = 0; 即num从 0 开始
num < 10; 即只要 num 小于 10
num++ 即每次循环完让 num 加 1
整句话直译成大白话就是：
“对于 num 从 0 到 9 的每一个数字，都执行一遍大括号里的代码。”
*/


/*本质上是把拆分的代码拼在一起，如下：
int num = 0
for( ; ; )
    {
        if(num >= 10)
        {
          break;
        }
        cout << num <<endl;
        num++;
    }
    return 0;
*/