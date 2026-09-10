/*多条件的if语句 语法如下：
if(条件1){条件1满足执行的语句}else if(条件2){条件2满足执行的语句}...else{各个条件都不满足执行的语句}
注意，从条件1顺序执行，若条件1满足，则执行条件1结束，若条件1不满足，则查看条件2满足与否，以此类推，其实就是if else嵌套
*/
#include <iostream>
using namespace std;
int main()
{
    //用户输入分数，如果分数大于等于650，则视作考上985，如果分数大于等于600，则视作考上211，如果分数大于等于550，则视作考上一本，其余视作考的不好，在屏幕上输出
    int score = 0;
    cout << "请输入你的分数" <<endl;
    cin >> score; 
    cout << "你高考成绩为" << score <<endl;
    if (score >= 650)//这后面没有分号；
    {
        cout << "恭喜你考上了985" <<endl; 
    }//这后面没有分号；
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