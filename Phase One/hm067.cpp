/*8.5 结构体嵌套结构体
作用：结构中的成员可以是另一个结构体
例如：每个老师辅导一个学生，一个老师的结构体中，记录一个学生的结构体

*/
#include <iostream>
using namespace std;

struct student //struct student 必须在 struct teacher 之前，因为struct teacher 里面调用 struct student了
{
    string name;
    int age;
    int score;
};

struct teacher
{
    int id;
    string name;
    int age;
    struct student stu;//调用struct student
};

int main()
{   
    teacher t;
    t.id = 98;
    t.name = "力士";
    t.age = 27;
    t.stu.age = 17;
    t.stu.name = "章平";
    t.stu.score = 600;
    cout << "老师的姓名为：" << t.name << " 编号为：" << t.id << " 年龄为：" << t.age <<endl<< 
    "所教学生为：" << t.stu.name << " 学生年龄为：" << t.stu.age << " 成绩为：" << t.stu.score <<endl;

    return 0;
}