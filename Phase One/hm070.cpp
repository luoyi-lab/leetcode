/*8.8 结构体案例
8.8.1 案例1
案例描述：学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下：
设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师以及所带的学生赋值
最终打印出老师数据以及老师所带学生的数据
*/
#include <iostream>
using namespace std;
#include <string>
#include <ctime>  

struct student
{
    string Sname;
    int score;

};

struct teacher
{
    string Tname;
    struct student Sarry[5];

};

//给老师和学生赋值的函数
void allocateSpace(struct teacher Tarry[] , int len )//struct teacher Tarry[]：接收一个 teacher 类型的数组（实际上传进来的是数组的首地址，这样才能修改 main 函数里的原始数据）
{
    string nameSeed = "ABCDE";
    for (int i = 0 ; i <len ; i++ )
    {
        Tarry[i].Tname = "Teacher_";
        Tarry[i].Tname += nameSeed[i];

        //通过循环给每个老师所带的学生赋值
        for(int j = 0 ; j < 5 ; j++)
        {
            Tarry[i].Sarry[j].Sname = "Student_";
            Tarry[i].Sarry[j].Sname += nameSeed[j];//C++ 中的 string 类型（字符串）重载了 += 运算符，它允许你把一个单个字符直接拼接到字符串的末尾
            int random = rand() % 61 + 40;//取模61，得到0-60的数值，加40，得到40-100的数值
            Tarry[i].Sarry[j].score = random;
        }
        
    }

}

//打印的函数
void printInfo(struct teacher Tarry[] , int len)
{
    for(int i = 0 ; i <len ; i++)
    {
        cout<< "老师的姓名为：" << Tarry[i].Tname <<endl;
        for (int j = 0 ; j < 5 ; j++)
        {
            cout<< "\t学生的姓名为：" << Tarry[i].Sarry[j].Sname << " 考试分数为：" << Tarry[i].Sarry[j].score <<endl;
        }

    }
}

int main()
{   
    srand((unsigned int)time(NULL)); // 设置随机种子，放在 main 开头
    //创建三名老师的数组
    struct teacher Tarry[3];
    int len = sizeof(Tarry)/sizeof(Tarry[0]);
    allocateSpace(Tarry,len);
    printInfo(Tarry,len);

    return 0;
}