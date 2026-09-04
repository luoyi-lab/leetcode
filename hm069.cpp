/*8.7 结构体中const使用场景
作用：用const来防止误操作
*/
#include <iostream>
using namespace std;

struct student
{
    string name;
    int age;
    int score;

};

void printstudents( struct student s)//这个s和main中的s不是一个东西
{
    cout << "子函数中打印的结果为" << " 姓名：" << s.name << " 年龄：" << s.age << " 成绩：" << s.score <<endl;

}

//将函数中的形参改为指针，可以减少内存空间，而且不会复制出新的副本出来，但是地址传递会误改实参的内容，故加上const，使得实参不可修改
void printstudents( const student * s)
{
    // s->age = 30; 不可修改，可以防止误操作

    cout << "子函数中打印的结果为" << " 姓名：" << s->name << " 年龄：" << s->age << " 成绩：" << s->score <<endl;

}

int main()
{   
    struct student s = {"张三" , 16 , 580};
    printstudents(s);

    return 0;
}