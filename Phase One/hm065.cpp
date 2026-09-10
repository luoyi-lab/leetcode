/*8.3 结构体数组
作用：将自定义的结构体放入到数组中方便维护和访问
语法：struct 结构体名 数组名[元素个数] = { {},{},......};
*/
#include <iostream>
#include <string> 
using namespace std;

//1.创建学生数据类型：学生包括（姓名、年龄、分数）
struct Student
{
    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;
};
int main()
{
    struct Student arr[3] = 
    {
        {"张三" , 18 ,90},
        {"李四" , 19 ,95},
        {"王五" , 17 ,80}
    };

    arr[2].name = "赵六";//典型错误：Student arr[2].name = "赵六"  不能再加Student

    for (int i = 0 ; i < 3 ; i++)
    {
        cout << arr[i].name << arr[i].age << arr[i].score <<endl;//cout不能识别结构体 只能识别int string等数据类型，故必须这样输出
    }
    return 0;
}