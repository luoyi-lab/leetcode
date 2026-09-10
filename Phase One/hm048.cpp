/*5.3.2 二维数组的数组名
1.查看二维数组所占的内存空间
2.获取二维数组首地址
*/
#include <iostream>
using namespace std;
int main()
{
    //1.查看二维数组所占的内存空间
    int arr[2][3] = 
    {
        {10,20,30},
        {40,50,60}
    };
    cout << "二维数组占用的空间为：" << sizeof(arr) <<endl; //根据数据类型确定占用的空间
    cout << "二维数组第一行占用的空间为：" << sizeof(arr[0]) <<endl;
    cout << "二维数组第一个元素占用的空间为：" << sizeof(arr[0][0]) <<endl;
    //如何看有几行或几列？  
    cout << "有几行：" << sizeof(arr)/sizeof(arr[0]) <<endl;
    cout << "有几列：" << sizeof(arr[0])/sizeof(arr[0][0]) <<endl;  //一行的内存除以一个元素的内存


    //2.获取二维数组首地址
    cout << "二维数组的首地址为" << arr <<endl;//  这里的首地址就是第一行地址，转为十进制：cout << "二维数组的首地址为" << (int)arr <<endl;
    cout << "二维数组中第一行数据的首地址为" << arr[0] <<endl;
    cout << "二维数组中第二行数据的首地址为" << arr[1] <<endl;
    cout << "二维数组中第一个元素的首地址为" << arr[0][0] <<endl;
    
    return 0; 
}