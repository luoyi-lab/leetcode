#include <iostream>
#include <vector>
using namespace std;

// 思考 我要创建一个传入数组 与目标 得到两数字之和的结果 这是一个标准的类的操作
class Solution
{
public:
    vector<int> Two_Sum (vector<int> & nums,int target)
    {
        // 外层循环找第一个数
        for(int i = 0 ; i < nums.size() ; i++)
        {
            // 内层循环 从第一个数后面开始找
            for(int j = i+1 ; j < nums.size() ; j++)
            {
                //判断两数之和是否等于target
                if(nums[i] + nums[j] == target)
                {
                    return {i , j};  //花括号 {} 可以用来给任何对象提供初始值
                }
            }
        }
        return {}; // 如果没找到，返回空 vector 
    }
};

int main()
{
    Solution S;
    vector<int> nums = {2,4,5,11,7,9};
    int target = 16;
    vector<int> res = S.Two_Sum(nums,target); ////调用twoSum函数 把结果存入到res数组里面
    cout << res[0] <<" "<< res[1] <<endl; //这里没法像python一样直接输出res数组 C++中必须先进行运算符重载
}
