/*8.8.2 案例2
案例描述：
设计一个英雄结构体，包括成员姓名，年龄，性别；创建结构体数组，数组中存放5名英雄。
通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排列，最终打印排序后的结果。

五名英雄如下：
    {"刘备", 23, "男"},
    {"关羽", 22, "男"},
    {"张飞", 20, "男"},
    {"赵云", 21, "男"},
    {"貂蝉", 19, "女"},
*/
#include <iostream>
using namespace std;

struct Hero
{
    string name;
    int age;
    string gender;

};

//冒泡排序函数
void bubbleSort(struct Hero heroarray[] , int len)
{
    for(int i = 0 ; i < len ; i++)
    {
        for( int j = 0 ; j < len - i -1 ; j++)//详见冒泡排序
        {
            //如果j下标的元素年龄大于j+1下标的元素年龄，交换两个元素
            if(heroarray[j].age > heroarray[j+1].age)
            {
                struct Hero temp = heroarray[j];
                heroarray[j] = heroarray[j+1];
                heroarray[j+1] = temp;//这里不加.age，是因为这是整个结构体的交换，不是只交换年龄
            }
        }
    }

};

void printHero(struct Hero heroarray[] , int len)
{
    for (int i = 0 ; i < len ; i++)
    { 
        cout << " 姓名：" << heroarray[i].name << " 年龄：" << heroarray[i].age << " 性别：" << heroarray[i].gender <<endl;
    }

};

int main()
{   
    struct Hero heroarray[5] = 
    {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"},
    };

    int len = sizeof(heroarray)/sizeof(heroarray[0]);

    for (int i = 0 ; i < len ; i++)
    { 
        cout << " 姓名：" << heroarray[i].name << " 年龄：" << heroarray[i].age << " 性别：" << heroarray[i].gender <<endl;
    }
    
    cout << "排序后如下" <<endl;

    bubbleSort(heroarray, len);//括号里直接写变量名或数组名就行，只有当函数形参需要接收某个普通变量的地址（指针）时，你才需要用取地址符 &
    printHero(heroarray,len);

    return 0;
}