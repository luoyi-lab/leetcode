/*多行格式if语句 语法如下：
if(条件){条件满足执行的语句}else{条件不满足执行的语句}
*/
#include <iostream>
using namespace std;
int main()
{
    //选择结构 单行if语句
    //用户输入分数，如果分数大于等于600，则视作考上好大学，在屏幕上输出
    int score = 0;
    cout << "请输入你的分数" <<endl;
    cin >> score; 
    if (score >= 600)//这后面没有分号；
    {
        cout << "恭喜你考上了名牌大学" <<endl; 
    }//这后面没有分号；
    else
    {
        cout << "抱歉，再接再厉" <<endl;
    }
    return 0;
}