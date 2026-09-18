/*封装的意义二：
类在设计时，可以把属性和行为放在不同的权限下，加以控制
访问权限有三种：
1.public  公共权限
2.protected  保护权限
3.private 私有权限
*/
#include <iostream>
using namespace std;

//访问权限
//三种
//公共权限  成员  类内可以访问，类外也可以访问
//保护权限  成员  类内可以访问，类外不可以访问  儿子也可以访问父亲中的保护内容
//私有权限  成员  类内可以访问，类外不可以访问  儿子不可以访问父亲的私有内容

class Person
{
public:
    //公共权限
    string m_Name;//姓名

protected:
    //保护权限
    string m_Car;//汽车

private:
    //私有权限
    int m_Password;//银行卡密码

public:
    void func()
    {
        m_Name = "张三";
        m_Car = "兰博基尼";
        m_Password = 777861;//这都属于类内内容
    }
};

int main()
{
    //实例化一个具体对象
    Person p1;
    p1.m_Name = "李四";//公共权限 类外也可以访问
    //p1.m_Car = "奔驰"  保护权限 类外不可以访问
    p1.func();//公共权限

    return 0;
}