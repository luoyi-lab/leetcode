/*练习案例2 数组元素逆置
描述：请声明一个5个元素的数组，并且将元素逆置
（如原数组为：1，2，3，4，5；逆置后输出结果为：5，4，3，2，1）

第一个元素下标为0   最后一个元素下标为 sizeof(arr)/sizeof(arr[0]) - 1 
start和end下标 的元素进行互换  思路为：先创建一个临时的变量，将第一个元素数据放进去，把最后一个元素数据覆盖到第一个元素，再把临时变量的数据覆盖到最后一个元素，这样实现start和end互换
int temp = arr[start];
arr[start] = arr[end];
arr[end] = temp;
start++;  end--;             如果start < end 执行互换

*/
#include <iostream>
using namespace std;
int main()
{
    int arr[] = { 1,3,2,5,4 };
    cout << "输出数组逆置前的结果" <<endl;
    for ( int i = 0 ; i < 5 ; i++ )//这个for循环的用处就是可以把数组中的元素输出出来
    {
        cout << arr[i] << " ";
    }
    //根据以上思路，实现逆置
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        //首尾已经互换了，往中间推
        start++;
        end--;
    }
    cout << "输出数组逆置后的结果" <<endl;
    for ( int j = 0 ; j < 5 ; j++ )
    {
        cout << arr[j] << " ";
    }
    return 0; 
}