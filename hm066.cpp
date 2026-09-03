/*8.4 结构体指针
作用：通过指针访问结构体中的成员

利用操作符 -> 可以通过结构体指针访问结构体属性
*/
#include <iostream>
using namespace std;

struct student
{
    string name;
    int age;
    int score;

};

int main()
{   
    struct student S = { "张三" , 18 , 100 };

    //通过指针指向结构体变量  经典错误：int * p = &S; 很明显，int这个数据类型不能囊括这个结构体
    struct student * p = &S;
    p->age;  //对比之前的 * p
    cout << "年龄为：" << p->age <<endl;
    cout << "姓名为：" << p->name <<endl;
    cout << "分数为：" << p->score <<endl;

    return 0;
}