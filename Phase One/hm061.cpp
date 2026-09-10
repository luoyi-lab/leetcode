/*7.6 指针和数组 作用：利用指针访问数组中的元素
*/
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout << arr[0] <<endl;
    int * p = arr;//arr就是数组的首地址
    cout << "利用指针来访问第一个元素：" << *p <<endl;
    p++;//让指针向后偏移4个字节，即到达数组的第二个元素
    cout << "利用指针来访问第二个元素：" << *p <<endl;

    int * p2 = &arr[1];
    cout << "利用指针来访问第二个元素：" << *p2 <<endl;
    
    //利用for循环和指针遍历数组
    for (int i = 0 ; i <10 ; i++ )
    {
        int * p3 = &arr[i];
        cout << "利用指针来访问元素：" << *p3 <<endl;
    }
   /*另一种写法如下：
   for (int i = 0 ; i <10 ; i++ )
    {
        cout << "利用指针来访问元素：" << *p3 <<endl;
        p++;
    }
   */

    return 0;
}