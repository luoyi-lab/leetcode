/*4.3 跳转语句
4.3.1 break语句 用于跳出选择结构或循环结构
使用时机如下：
1.出现在switch条件语句中，作用是终止case并跳出switch
2.出现在循环语句中，作用是跳出当前的循环语句
3.出现在嵌套语句中，跳出最近的内层循环语句
*/
#include <iostream>
using namespace std;
int main()
{
    //出现在switch条件语句中，作用是终止case并跳出switch
    cout << "请选择副本的难度 " <<endl;
    cout << "1.普通 " <<endl;
    cout << "2.中等 " <<endl;
    cout << "3.困难 " <<endl;
    int select = 0;//创建选择结果的变量
    cin >> select;//等待用户输入
    switch(select)
    {
        case 1:
        cout << "您选择的是普通难度" <<endl;break;//如果没有break，当选择1之后，它会把顺序接下来的三个case的结果全部打印出来
        case 2:
        cout << "您选择的是中等难度" <<endl;break;
        case 3:
        cout << "您选择的是困难难度" <<endl;break;
        default:
        break;
    }

    //出现在循环语句中
    for ( int i = 0 ; i < 10 ; i++ )
    {
        if ( i == 5)
        {
            break;
        }
        cout << i << endl;
    }

    //出现在嵌套语句中，本质也是退出循环语句
    for (int i = 1 ; i <= 9 ; i++ )
    {
        for (int j = 1 ; j <= 9 ; j++ )
        {
            cout << "* " ;
            if ( j == 5)
            {
                break;
            }
        }
        cout << endl;
    }
    return 0;
}