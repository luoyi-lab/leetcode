/*2.7 布尔类型 bool 代表真或假的值 多用于判断
bool类型只有两个值：即在 = 后面只能有这两个值，不同于之前的数据类型
1.true 真 本质是1
2.false 假 本质是0
bool类型仅占1个字节大小
*/
#include <iostream>
using namespace std;
int main()
{
    bool flag1 = true;
    bool flag2 = false;
    cout << flag1 <<endl;//输出为1
    cout << flag2 <<endl;//输出为0
    cout << "flag2所占的字节为" << sizeof(flag2) <<endl;//输出为0
    cout << "bool类型所占的字节为" << sizeof(bool) <<endl;//输出为0
    return 0;
}