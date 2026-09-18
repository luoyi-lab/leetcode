/*4.1.3 成员属性设置为私有
优点1：将所有成员属性设置为私有，可以自己控制读写权限
优点2：对于 写 权限，我们可以检测数据的有效性
*/
#include <iostream>
using namespace std;
#include <string>

//成员属性设置私有
//人类
class Person
{
public:
    //设置姓名（也就是写的操作）
    void setName(string name)
    {
        m_Name = name;
    }

    //获取姓名（也就是读的操作）
    string getName()
    {
        return m_Name;
    }

    //获取年龄
    int getAge()
    {
        return m_Age;
    }

    //设置年龄 0-120
    void setAge(int age)
    {
        if(age < 0 || age >120)
        {
            cout << "年龄输入有误，赋值失败" <<endl;
            return;//立即结束当前函数，返回到调用处
        }
        m_Age = age;
    }

    //设置偶像
    void setIDOL(string idol)
    {
        m_IDOL = idol;
    }
private://先都私有化，要干啥再通过上面的公共成员函数来实现
    string m_Name;//姓名 可读可写

    int m_Age = 18;//年龄 只读 也可以写（但必须在0-120）

    string m_IDOL;//只写

};

int main()
{
    Person p;
    //姓名设置
    p.setName("张三"); //实现了写的操作
    cout << "姓名：" << p.getName() <<endl;
    p.setAge(26);
    cout << "年龄：" << p.getAge() <<endl;//读取年龄，同时不改写年龄
    p.setIDOL("王力宏");//实现了写的操作

    return 0;
}