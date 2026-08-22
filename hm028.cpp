/*选择结构案例 三只小猪称体重 具体如下：
有三只小猪ABC 请分别输入三只小猪的体重 并且判断哪只小猪最重？
纯用if语句来做，锻炼一下
*/
#include <iostream>
using namespace std;
int main()
{
    int A = 0;
    int B = 0;
    int C = 0;
    cout << "请输入小猪A的体重：" <<endl;
    cin >> A;
    cout << "请输入小猪B的体重：" <<endl;
    cin >> B;
    cout << "请输入小猪C的体重：" <<endl;
    cin >> C;
    cout << "小猪A B C的体重分别为：" << A << "和" << B << "和" << C <<endl;
    if( A > B)
    {
        if ( A > C )
        {
            cout << "小猪A最重" <<endl;
        }
        else
        {
            cout << "小猪C最重" <<endl;
        }
    }
    else
    {
        if ( B > C )
        {
            cout << "小猪B最重" <<endl;
        }
        else
        {
            cout << "小猪C最重" <<endl;
        }
    }
    return 0;
}