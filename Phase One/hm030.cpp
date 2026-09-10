/*4.1.3 switch语句 用来执行多条件分支语句 语法如下：
switch(一个变量：整型或字符型)
{
  case 结果1：执行语句;break;

  case 结果2：执行语句;break;
  
  ...
  
  default: 执行语句;break;
}
switch 只适合判断「等于某个具体值」（比如星期几：case 1、case 2...）
另外注意：如果判断的是区间，这种应该用 if/else if
*/
#include <iostream>
using namespace std;
int main()
{
    //给电影进行打分
    //10-9 超级好
    //8-7  比较好
    //6-5  一般般
    //5分以下  烂片
    cout << "请给电影打分：" <<endl;
    int score;//注意这里初始值可以忽略
    cin >> score;
    cout << "你打的分数为：" << score <<endl;
    switch(score)
    {
        case 10 : 
          cout << "这部电影超级好看" <<endl;break;//break表示退出当前分支
        case 9 : 
          cout << "这部电影超级好看" <<endl;break;
        case 8 :
          cout << "这部电影好看" <<endl;break;
        case 7 : 
          cout << "这部电影好看" <<endl;break;
        case 6 : 
          cout << "这部电影一般般" <<endl;break;
        case 5 : 
          cout << "这部电影一般般" <<endl;break;
        default : 
          cout << "这部电影很烂" <<endl;break;
    }
    return 0;
}