/*5.2.2 一维数组 数组名称的用途：
1.可以统计整个数组在内存中的长度   统计整个数组：sizeof(arr)      统计某一个元素：sizeof( arr[0] )    以上两者相除为元素的个数
2.可以获取数组在内存中的首地址（就是第一个元素的地址）    十六进制：cout << arr <<endl;           十进制：cout << (int)arr <<endl;
*/
#include <iostream>
using namespace std;
int main()
{
    int arr [] = { 1,2,3,4,5,6,7,8,9,10 };
    cout << sizeof(arr) <<endl;
    cout << sizeof(arr[0]) <<endl;
    cout << "数组中元素个数为：" << sizeof(arr)/sizeof(arr[0]) <<endl;//可以这样搞的原因是数组中每个元素的数据类型是一样的，故占据的内存空间也是一样的

    cout << "数组的首地址为：" << arr <<endl;
    //cout << "数组的首地址为：" << (int)arr <<endl;
    cout << "第二个元素的地址为：" << arr[10] <<endl;
    //cout << "第二个元素的地址为：" << (int)&arr[1] <<endl;
    return 0; 
}
// 数组名是一个常量，不可以进行赋值，定义其他变量名称时，要避开已经定义的数组名