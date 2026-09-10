/*4.3.2 continue语句
作用：在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环
和break的区别：break是直接跳出循环整体结束了，continue是结束这一次循环的代码，进入下一个循环
*/
#include <iostream>
using namespace std;
int main()
{
    for ( int i = 0 ; i <= 100 ; i++ )
    {
        //如果是奇数则输出，偶数就不输出了
        if ( i % 2 == 0)
        {
            continue;//跳过偶数，其实想要实现这段代码有很多种写法，比如直接用if来写 i % 2 != 0
        }
        cout << i << endl;
    }
    return 0;
}