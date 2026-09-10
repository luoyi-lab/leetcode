/*8.6 结构体做函数参数
作用：将结构体作为参数向函数中传递，传递方式有两种如下：
1.值传递    回忆一下：值传递，只是把我复制了一下，复制体变化，我本身没有变化
2.地址传递  回忆一下：地址传递，是将内存地址直接告诉别人，别人根据这个地址，直接找到我，可以直接改变我
*/
#include <iostream>
using namespace std;

struct student //将学生传入到一个参数中，打印学生身上的所有信息
{
    string name;
    int age;
    int score;
};

//打印学生信息的函数
//1.值传递
void PrintStduent1(struct student s)//把main里面定义的值复制传递进去了
{
    s.age = 100; //不改变实参main函数中年龄不会变为100
    cout << "子函数1中打印的结果为" << " 姓名：" << s.name << " 年龄：" << s.age << " 成绩：" << s.score <<endl;

}

//2.地址传递
void PrintStduent2(struct student * p)//这里的 p 就是形参  “将来谁调用我，请给我一个 struct student 类型的指针，我会用 p 这个变量名来接收它。”
{
    p->age = 80;//实参也被改变了
    cout << "子函数2中打印的结果为" << " 姓名：" << p->name << " 年龄：" << p->age << " 成绩：" << p->score <<endl;
}

int main()
{   
    struct student s;
    s.name = "张三";
    s.age = 18;
    s.score = 630;
    cout << "main函数中打印的结果为" << " 姓名：" << s.name << " 年龄：" << s.age << " 成绩：" << s.score <<endl;

    PrintStduent1(s);//在 PrintStduent1(s); 中，s 可以直接放在括号里，是因为 s 的类型与函数参数的类型完全匹配。
                     //函数 PrintStduent1 的定义是 void PrintStduent1(struct student s)，它要求传入一个 struct student 类型的参数。

    cout << "main函数中打印的结果为" << " 姓名：" << s.name << " 年龄：" << s.age << " 成绩：" << s.score <<endl;

    PrintStduent2(&s);

    cout << "main函数中打印的结果为" << " 姓名：" << s.name << " 年龄：" << s.age << " 成绩：" << s.score <<endl;

    return 0;
}