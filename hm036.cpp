/*循环结构案例 敲桌子
描述：从1开始数到数字100，如果数字含有7或者是7的倍数，我们打印敲桌子，其余数字直接打印输出
思路：
1.先把1-100全部输出
2.找到特殊数字，输出敲桌子
  
  特殊数字：   
  7的倍数         num % 7  = 0
  个位有7         num % 10 = 7
  十位有7         num / 10 = 7
*/

//用while循环如下：
#include <iostream>
using namespace std;
int main()
{
    int num = 1;
    while(num <= 100)
    {
      if (num % 7 == 0 || num % 10 == 7 || num / 10 == 7 )// 注意一定是 == 而不是 =
      {
       cout << "敲桌子" <<endl;
      }
      else
      {
        cout << num <<endl;
      }
      num++;
    }
    return 0;
}

// 用for循环如下：
#include <iostream>
using namespace std;
int main()
{
    for (int i = 1 ; i <= 100 ; i++ )
    {
        if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7 )
      {
       cout << "敲桌子" <<endl;
      }
      else
      {
        cout << i <<endl;
      }
    }
    return 0;
}