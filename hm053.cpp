/*6.5 函数的常见样式  常见的函数样式有4种如下：
1.无参无返
2.有参无返
3.无参有返
4.有参有返
*/
#include <iostream>
using namespace std;
//1.无参无返
void test01()
{
    cout << "this is test01" <<endl;
}

//2.有参无返
void test02(int a)
{
    cout << "this is test02 a = " << a <<endl;
}

//3.无参有返
int test03()
{
    cout << "this is test03 " <<endl; 
    return 1000;
}

//4.有参有返
int test04( int num1 , int num2 )
{
    int sum = num1 + num2;
    return sum;
}

int main()
{
    //1.无参无返
    test01();//依旧是函数内部有输出，故直接放一个test01()，直接就有输出了

    //2.有参无返
    int a = 10;
    test02(a);
    

    //3.无参有返
    int b = test03();//这里也可以不用变量b去接受函数结果，直接cout也可以接受 
    cout << "b = " << b <<endl;
    cout << test03() <<endl;

    //4.有参有返
    int c = 8;
    int d = 10;
    int e = test04(c,d);//  return的sum直接赋值给了e
    cout << e <<endl;

    return 0;
}