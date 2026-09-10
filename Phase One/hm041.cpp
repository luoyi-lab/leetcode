/*4.3.3 goto语句 可以无条件的跳转语句
语法： goto 标记;

标记：

解释：如果标记的名称存在，执行到goto语句时，会跳转到标记的位置
*/
#include <iostream>
using namespace std;
int main()
{
    cout << "111" <<endl;
    cout << "222" <<endl;
    goto FLAG;
    cout << "333" <<endl;
    cout << "444" <<endl;
    FLAG:
    cout << "555" <<endl;
    return 0;
}
//注意在程序中尽量不要使用goto，以免造成程序流程混乱