/*8 结构体
8.1 结构体基本概念 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型
8.2 结构体的定义和使用

语法：
struct 结构体名
{
    结构体成员列表
};

通过结构体创建变量的方式有三种：
1.struct 结构体名 变量名
2.struct 结构体名 变量名 = {成员1值 , 成员2值}
3.定义结构体时顺便创建变量
*/
#include <iostream>
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
}s3;//定义结构体时顺便创建变量

//2.通过学生类型创建具体的学生

//第一种：struct 结构体名 变量名                                  struct Student s1;
//第二种：struct 结构体名 变量名 = {成员1值 , 成员2值}             struct Student s2 = {  ...  };  把s2变量的初始值也给了
//第三种：定义结构体时顺便创建变量


int main()
{
    //第一种
    struct Student s1;
    s1.age = 18;//通过 . 来访问结构体中的属性
    s1.name = "张三";
    s1.score = 100;
    cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 成绩：" << s1.score <<endl;

    //第二种
    struct Student s2 = {"李四" , 17 , 90};
    cout << "姓名：" << s2.name << " 年龄：" << s2.age << " 成绩：" << s2.score <<endl;

    //第三种
/*  struct Student
   {
        string name;
        int age;
        int score;
    }s3;
*/
    s3.age = 19;
    s3.name = "王五";
    s3.score = 85;
    cout << "姓名：" << s3.name << " 年龄：" << s3.age << " 成绩：" << s3.score <<endl;
    
    return 0;
}
//用第一和第二两种比较多
//实际上在C++中 创建结构体变量时struct关键字可以省略
//即直接 Student s1; 也可以