/*1.5 关键字 即C++中预先保留的一些单词（标识符） 在定义变量或常量时，要避开关键字
关键字如下：
asm do if return typedef
auto double inline short typeid
bool dynamic_cast int signed typename 
break else long .....
详见关键字大全
*/

#include <iostream>
using namespace std;
int main()
{
    // 创建变量：数据类型 变量名 = 变量初始值
    //int const = 0 典型的错误代码
    int b = 8;
    cout << b <<endl;
    return 0;
}