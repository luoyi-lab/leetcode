/*示例2：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
补充关键术语：
类中的 属性 和 行为，统称为成员
属性 称为成员属性 或 成员变量
行为 成为成员函数 或 成员方法
*/
#include <iostream>
using namespace std;
#include <string>


//设计一个学生类
class Student
{
public: //公共权限
    
    //属性
    string m_Name;//姓名
    int m_ID;     //学号


    //行为
    void showStudent()//行为：显示学生的姓名和学号
    {
        cout << "姓名：" << m_Name << " 学号：" << m_ID <<endl;
    }

    //给姓名赋值
    void setName(string name)
    {
        m_Name = name;
    }

    //给学号进行赋值
    void setID(int ID)
    {
        m_ID = ID;
    }

};

int main()
{
    Student s1;//创建一个具体的学生，实例化对象
    s1.m_Name = "张三";//对对象的属性就行赋值
    s1.m_ID = 23;

    //显示学生信息，即对象的行为
    s1.showStudent();

    Student s2;
    s2.setName("罗五");//给姓名赋值的行为
    s2.setID(13);//给学号赋值的行为
    s2.showStudent();

    return 0;
}