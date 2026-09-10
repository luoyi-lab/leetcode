/*4.3.2 do...while循环语句 满足循环条件，执行循环语句 语法如下：
do{循环语句} while(循环条件)；
与while循环的区别在与do...while会先执行一次循环语句，再判断循环条件
*/
#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    do
    {
        cout << num <<endl;
        num ++;
    } 
    while (num < 10);
    return 0;
}