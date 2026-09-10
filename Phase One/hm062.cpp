/*7.7 指针和函数
作用：利用指针作函数参数，可以修改实参的值

*/
#include <iostream>
using namespace std;
//值传递（函数中的形参改变，int main里面的实参没有变，详见前面课程）
/*void swap1(int a , int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "sawp1 a = " << a <<endl;
    cout << "sawp1 b = " << b <<endl;
}

int main()
{
    int a = 10;
    int b = 20;
    swap1(a,b);
    cout << " a = " << a <<endl;
    cout << " b = " << b <<endl;
    return 0;
}
*/

//地址传递  把实参修改了
void swap2(int * p1 , int * p2)//这里面的形参是 p1 p2
{
    int temp = *p1;
    *p1 = *p2;             //解引用，根据地址直接修改了内存数据
    *p2 = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    swap2(&a,&b);
    cout << " a = " << a <<endl;
    cout << " b = " << b <<endl;
    return 0;

    /*解释一下 
    
    值传递中 形参实际上是实参值的副本  函数修改了这个副本的内存                                        能影响实参
    地址传递中 形参的内容是实参的内存地址  函数直接找到了这个实参所在的地址，改变了里面的内存数据        可以影响实参

    一句话总结：地址传递让函数“看”到了实参的家门（地址），所以能进门搬东西（修改数据）；值传递只给了函数一张“照片”（副本），搬照片不会影响真实的家。
    */
}