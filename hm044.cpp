/*练习案例1：五只小猪称体重
案列描述：在一个数组中记录了五只小猪的体重，如：int arr[5] = {300,350,200,400,250}
找出并打印最重的小猪体重
*/
#include <iostream>
using namespace std;
int main()
{
    //先设定一个最大值，再访问数组中的每个元素，如果这个元素比我认定的最大值要大，就更新最大值
    int arr[] = {300,600,350,500,360};
    int max = 0;
    for(int i = 0 ; i <=5 ; i++ )
    {
        if(arr[i] >= max )
        {
            max = arr[i];
        }
    }
    cout << "最重的小猪体重为：" << max <<endl;

    return 0; 
}