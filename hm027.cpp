/*嵌套if语句
案例需求：
提示用户输入一个高考分数，根据分数做如下判断：
分数如果大于650则视为考上985，大于600考上211，大于550考上一本，其余视为未考上一本
在一本分数中，如果大于700分，考入北大，大于680，考入清华，大于660，考入南大

*/
#include <iostream>
using namespace std;
int main()
{
int score = 0;
    cout << "请输入你的分数" <<endl;
    cin >> score; 
    cout << "你高考成绩为" << score <<endl;
    if (score >= 650)//这后面没有分号；
    {
        cout << "恭喜你考上了985" <<endl; 
        if (score >= 700)// if里面再套if
        {
            cout << "恭喜你考上了北大" <<endl;
        }
        else if (score >= 680)
        {
            cout << "恭喜你考上了清华" <<endl;
        }
         else if (score >= 660)
        {
            cout << "恭喜你考上了南大" <<endl;
        }
        else
        {
            cout << "很遗憾，你的高考成绩距离C9仍有一段距离" <<endl;
        }

    }
    else if (score >= 600)
    {
        cout << "恭喜你考上了211" <<endl;
    }
    else if (score >= 550)
    {
        cout << "恭喜你考上了一本" <<endl;
    }
    else
    {
        cout << "抱歉，未考上一本，请再接再厉" <<endl;
    }
    return 0;
}