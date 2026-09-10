/*3.3 比较运算符 用于表达式的比较 返回一个真值或假值 例子如下：
运算符           术语            示例              结果
==              相等于           4 == 3            0
!=              不等于           4 != 3            1
<                                4 < 3             0
>                                4 > 3             1
<=
>=

*/
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b =15;
    cout << (a == b) <<endl;
    cout << (a != b) <<endl;
    cout << (a < b) <<endl;
    cout << (a > b) <<endl;
    cout << (a <= b) <<endl;
    cout << (a >= b) <<endl;
    /*
    如果不加括号：
    cout << a == b << endl;
    编译器会理解成：先做 << 输出，再做 == 比较 —— 顺序乱了，结果就不是你要的（甚至报错）。
    加了括号：
    cout << (a == b) << endl;
    就明确告诉编译器：「先算 a == b，得到 true/false，再把结果输出」。
    */
    return 0;
}