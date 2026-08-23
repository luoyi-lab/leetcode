/*while循环案例：猜数字
系统随机生成一个1-100的数字，玩家进行猜测，如果猜错，提示玩家数字过大或是过小，如果猜对了则恭喜玩家胜利，并且退出游戏
*/
#include <iostream>
#include <ctime> //加这个头文件（提供 time 函数）
using namespace std;
int main()
{
    //rand()%100 /生成0-99的随机数
    srand(time(0)); //  加这一行：用当前系统时间做随机种子
    int num1 = rand() % 100 +1;
    int num2 = 0;
    int a = 1;
    cout << "请你猜数字：" <<endl;
    while( num1 != num2 )
    {
        cin >> num2;
        if (num1 > num2)
        {
            cout << "小了" <<endl;
        }
        else if(num1 < num2)
        {
            cout << "大了" <<endl;  
        }
        else
        {
            cout << "恭喜你猜对了" <<endl;
        }
    }
    return 0;
}

/*以下代码也可以
int main()
{
    //rand()%100 /生成0-99的随机数
    srand(time(0)); //  加这一行：用当前时间做随机种子
    int num1 = rand() % 100 +1;
    int num2 = 0;
    cout << "请你猜数字：" <<endl;
    while( 1 )                                 括号里面为1，即为真，代表无限循环
    {
        cin >> num2;
        if (num1 > num2)
        {
            cout << "小了" <<endl;
        }
        else if(num1 < num2)
        {
            cout << "大了" <<endl;  
        }
        else
        {
            cout << "恭喜你猜对了" <<endl;
            break;                               break用来退出无限循环
        }
    }
    return 0;
}
*/




/*限制猜测次数
int main()
{
    srand((unsigned)time(0));
    int num1 = rand() % 100 + 1; // 1~100
    int num2 = 0;
    int count = 0; // 已猜次数

    cout << "猜数字（1~100），你只有5次机会：" << endl;

    while (count < 5)   // 还有机会时继续
    {
        cin >> num2;
        count++; // 每次输入算一次猜测

        if (num1 > num2)
        {
            cout << "小了，还剩 " << (5 - count) << " 次机会" << endl;
        }
        else if (num1 < num2)
        {
            cout << "大了，还剩 " << (5 - count) << " 次机会" << endl;
        }
        else
        {
            cout << "恭喜你猜对了！你用了 " << count << " 次。" << endl;
            return 0; // 猜对直接结束程序
        }
    }

    // 循环结束（即 count == 5）仍未猜对
    cout << "很遗憾，5次机会用完了。正确答案是：" << num1 << endl;
    return 0;
}
 */