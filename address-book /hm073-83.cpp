/*2.创建项目 在leetcode[WSL:Ubuntu]里面新建文件夹，在这个文件夹里面写该项目
3.菜单功能
4.退出功能
思路：根据用户不同的选择，进入不同的功能，可以选择switch分支结构，将整个架构进行搭建
当用户选择0的时候，执行退出，选择其他先不做操作，也不会退出程序
5.添加联系人功能
联系人上限为1000人，联系人信息包括：姓名、性别、年龄、联系电话、家庭住址
添加联系人实现步骤：
  设计联系人结构体
  设计通讯录结构体
  main函数中创建通讯录
  封装添加联系人函数
  测试添加联系人功能
6.显示联系人
实现步骤：
  封装显示联系人函数
  测试显示联系人功能
7.删除联系人
实现步骤：
  封装检测联系人是否存在
  封装删除联系人函数
  测试删除联系人功能
8.查找联系人
实现步骤：
  封装查找联系人函数
  测试查找指定联系人
9.修改联系人
按照姓名重新修改指定联系人
实现步骤：
  封装修改联系人函数
  测试修改联系人函数
10.清空联系人
实现步骤：
  封装清空联系人函数  思路：不需要逐个清空信息，只要将通讯录记录的联系人数量置为0，做逻辑清空就行
  测试清空联系人
*/
#include <iostream>
using namespace std;
#include<string>
#define MAX 1000

//菜单界面
void showMenu()
{
    cout << "1. 添加联系人" <<endl;
    cout << "2. 显示联系人" <<endl;
    cout << "3. 删除联系人" <<endl;
    cout << "4. 查找联系人" <<endl;
    cout << "5. 修改联系人" <<endl;
    cout << "6. 清空联系人" <<endl;
    cout << "0. 退出通讯录" <<endl;

}

//5.1 设计联系人结构体
struct Person
{
    string m_Name;
    int m_Sex;//1男 2女
    int m_Age;
    string m_Phone;
    string m_Addr;
};

//5.2 设计通讯录结构体
struct Addressbooks
{
    struct Person personArray[MAX];//通讯录中保存的联系人数组
    int m_Size;
};

//1.添加联系人
void addPerson(Addressbooks * abs)//括号里面是指针变量
{
    //判断通讯录是否已经满了
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加" <<endl;
        return;
    }

    else//添加具体的联系人
    {
        //姓名
        string name;
        cout << "请输入姓名：" <<endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //性别
        cout << "请输入性别：" <<endl;
        cout << "1--男" <<endl;
        cout << "2--女" <<endl;
        int sex = 0;
        
        while(true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "输入错误，请重新输入" <<endl;
            }
        }
        
        //年龄
        cout << "请输入年龄：" <<endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //电话
        cout << "请输入电话：" <<endl;
        string phone;
        cin >>phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //住址
        cout << "请输入住址：" <<endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //更新通讯录中的人数
        abs->m_Size ++;

        cout << "添加成功" <<endl;

        //在这里添加暂停 
        cin.ignore(1024, '\n');          // 清掉输入流里的回车
        cout << "按 Enter 键继续..." << endl;
        cin.get();  

        //清屏
        system("clear");
    }
};

//2.显示所有的联系人
void showPerson(Addressbooks * abs)
{
    //判断通讯录中人数是否为0
    if(abs->m_Size == 0)
    {
        cout << "当前记录为空" <<endl;
    }
    else
    {
        for(int i = 0 ; i < abs->m_Size ; i++)
        {
            cout << "姓名：" <<abs->personArray[i].m_Name <<"\t";
            cout << "性别：" <<(abs->personArray[i].m_Sex ==  1 ? "男" : "女") << "\t\t";//三目运算符 如果sex是1，输出男，如果sex是2，输出女
            cout << "年龄：" <<abs->personArray[i].m_Age <<"\t";
            cout << "电话：" <<abs->personArray[i].m_Phone <<"\t";
            cout << "住址：" <<abs->personArray[i].m_Addr <<endl;


        }
    }
    //在这里添加暂停 
        cin.ignore(1024, '\n');  // 清掉输入流里的回车
        cout << "按 Enter 键继续..." << endl;
        cin.get();  
        //清屏
        system("clear");
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExist(Addressbooks * abs , string name)//参数1 通讯录  参数2 对比姓名
{
    for(int i = 0 ; i < abs->m_Size ; i++ )
    {
        if( abs->personArray[i].m_Name == name)//找到用户输入的姓名了
        {
            return i;//找到了，返回该人在数组中的下标编号为i
        }
    }
    return -1;//如果遍历结束都没有找到，返回-1
}

//3.删除指定的联系人
void deletePerson(Addressbooks * abs)
{
    cout << "请输入要删除的联系人" <<endl;
    string name;
    cin >> name;

    //判断是否查询到这个人
    int ret = isExist(abs,name);//这里的abs是指针  这里的ret是该人的下标编号
    if(ret != -1)
    {
        //查到人，要进行删除，逻辑是：把要删除的这个人后面的所有数据整体向前挪一格覆盖掉这个人（数据一个一个向前移动），并且再把整个通讯录人数减1
        for(int i = ret ; i < abs->m_Size - 1 ; i++)
        {
            //数据前移
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size --;//通讯录人数减1
        cout << "删除成功" <<endl;
    }
    else
    {
        cout << "查无此人，请确认姓名是否正确" << endl;
       
    }

    cin.ignore(1024, '\n');  // 清掉输入流里的回车
    cout << "按 Enter 键继续..." << endl;
    cin.get();  
    system("clear");
}

//4.查找联系人信息
void findPerson(Addressbooks * abs)
{
    cout << "请输入您要查找的的联系人" <<endl;
    string name;
    cin >> name;

    //判断指定的联系人是否存在
    int ret = isExist(abs , name);//函数返回一个result结果
    
    if(ret != -1)
    {
        cout << "姓名：" <<abs->personArray[ret].m_Name <<"\t";
        cout << "性别：" <<(abs->personArray[ret].m_Sex ==  1 ? "男" : "女") << "\t\t";
        cout << "年龄：" <<abs->personArray[ret].m_Age <<"\t";
        cout << "电话：" <<abs->personArray[ret].m_Phone <<"\t";
        cout << "住址：" <<abs->personArray[ret].m_Addr <<endl;
    }
    else
    {
        cout << "查无此人" <<endl;
    }

    cin.ignore(1024, '\n');  // 清掉输入流里的回车
    cout << "按 Enter 键继续..." << endl;
    cin.get();  
    system("clear");
}

//5.修改指定联系人
void modifyPerson(Addressbooks * abs)
{
    cout << "请输入您要修改的联系人" <<endl;
    string name;
    cin >> name;

    int ret = isExist(abs , name);

    if(ret != -1)
    {
        //姓名
        string name;
        cout << "请输入姓名：" <<endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        //性别
        int sex = 0;
        cout << "请输入性别：" <<endl;
        cout << "1--男" <<endl;
        cout << "2--女" <<endl;
        
        while(true)//如果输入错了，则重新输入
        {
            cin >> sex;
            if(sex == 1||sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;//跳出最近的一层循环
            }

            cout << "输入错误，请重新输入（1或2）：" << endl; 
        }

        //年龄
        cout << "请输入年龄" <<endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;
        
        //电话
        cout << "请输入电话" <<endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        //住址
        cout << "请输入住址" <<endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "修改成功" <<endl;

    }
    else
    {
        cout << "查无此人" <<endl;
    }

    cin.ignore(1024, '\n');  // 清掉输入流里的回车
    cout << "按 Enter 键继续..." << endl;
    cin.get();  
    system("clear");
}

//6.清空联系人
void cleanPerson(Addressbooks * abs)
{
    cout << "确认要清空联系人吗"<< endl;
    cout << "1--确认" <<endl;
    cout << "2--取消" <<endl;
    int a = 0;
    cin >> a;
    if (a == 1)
    {
        abs->m_Size = 0;
        cout << "联系人已清空" <<endl;
    }
    else
    {
        cout << "已取消" <<endl;
    }
    
    cin.ignore(1024, '\n');  // 清掉输入流里的回车
    cout << "按 Enter 键继续..." << endl;
    cin.get();  
    system("clear");
}


int main()
{
    //创建通讯录结构体变量
    Addressbooks abs;
    //初始化通讯录中当前人员个数
    abs.m_Size = 0;

    int select = 0;//创建用户选择输入的变量

    while(true)//可以返回菜单页面（有return 0除外）
    {
           //菜单的调用
        showMenu();

        cin>>select;
        switch(select)
        {
            case 1:
                addPerson(&abs);//地址传递，才能真的修饰这个通讯录
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
                deletePerson(&abs);
                break;
            case 4:
                findPerson(&abs);
                break;
            case 5:
                modifyPerson(&abs);
                break;
            case 6:
                cleanPerson(&abs);
                break;
            case 0:
                cout << "欢迎下次使用" <<endl;
                return 0;
                break;
            default:
                break;
        }
    }

    return 0;
}