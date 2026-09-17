/*3.2 函数的占位参数
C++中函数的形参列表可以有占位参数，用来做占位，调用函数时必须填补该位置
语法：返回值类型 函数名(数据类型)
{
}

现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术
占位参数 还可以有默认参数  如：void func (int a , int = 10)

*/
#include <iostream>
using namespace std;

void func(int a , int )
{
    cout << "this is func" <<endl;

}

int main()
{
    func(10,10);//第二个10，在函数中是拿不到的，因为没有变量去接收它
    
    return 0;
}