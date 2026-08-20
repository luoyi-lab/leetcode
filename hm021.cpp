/*3.4 逻辑运算符 用于根据表达式的值返回真值或假值 例子如下：
运算符           术语            示例              结果
!                 非             !a               如果a为假 则!a为真；如果a为真，则!a为假
&&                与             a&&b             如果a和b都为真，则结果为真，否则为假
||                或             a||b             只要a和b其中一个为真，则结果为真，二者都为假，则结果为假
*/
#include <iostream>
using namespace std;
int main()
{
    //非
    int a = 10;
    cout << !a <<endl;//在C++中，数字中除0外都为真，也就是返回一个1
    int b = 0;
    cout << !b <<endl;//在C++中，数字中除0外都为真，也就是返回一个1
    cout << !(a == b) <<endl;//a不等于b
    cout << !(a >= b) <<endl;//a大于b
    //与
    cout << (a && b) <<endl;
    cout << ( (a >= b)&&(a != b) ) <<endl;//加括号明确运算顺序，让 && 先求值：
    //非
    cout << (a || b) <<endl;
    cout << ( (a >= b)||(a == b) ) <<endl;
    cout << ( (a == b)||(a <= b) ) <<endl;//二者都为假 结果才为假
    return 0;
}