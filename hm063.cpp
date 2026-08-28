/*7.8 指针、数组、函数
案列描述：封装一个函数，利用冒泡排序，实现对整型数组的升序排序
例如数组： int arr[10] = {4,3,6,9,1,2,10,8,7,5}
1.先创建数组
2.创建函数，实现冒泡排序
3.打印排序后的数组
*/
#include <iostream>
using namespace std;

//冒泡排序函数
void bubbleSort(int * arr , int len)//形参必须用指针 int * arr 来接住这个地址，arr 在这代表首地址，首地址加上数组长度，函数就可以控制整个数组了
{
    for( int i = 0; i < len-1 ; i++ )
    {
        for (int j = 0 ; j < len - i - 1 ; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }

    }

}
//打印数组
void PrintArry(int * arr , int len)
{
    for(int i = 0 ; i < len ; i++)
    { 
        cout << arr[i] <<endl;
    }

}

int main()
{
    int arr[10] = {4,3,6,9,1,2,10,8,7,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,len);//数组名在传参时会“退化”成指针
    PrintArry(arr,len);

    return 0;
}