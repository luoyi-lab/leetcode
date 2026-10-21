// 最大子数组和
/* 题目描述:
给你一个整数数组 nums，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组是数组中的一个连续部分。
示例1：输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
       输出：6
       解释：连续子数组 [4,-1,2,1] 的和最大，为 6 

示例2：输入：nums = [1]
       输出：1

示例3：输入：nums = [5,4,-1,7,8]
      输出：23

思考 核心解法叫：Kadane算法 卡达内算法 本质上是一种动态规划和贪心算法
这道题的灵魂：如果当前累加小于0，你必须立刻抛弃，重新开始算
示例：nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]  
定义：cur_num：当前这一段的总和
      max_sum：历史最高和纪录

步骤      当前数字       当前连续和       历史最大和       想法
1.          -2              -2             -2           负数 立刻放弃
2.           1               1              1            正数 继续
3.          -3              -2              1           负数  立刻放弃
4.           4              4               4             继续
5.           -1              3              4             继续
6.            2              5              5              继续
7.            1              6              6              继续
8.            -5             1              6               继续
9.            4              5              6                结束 输出历史最大和 max_sum = 6 
*/

#include <iostream>
#include <vector>
#include <algorithm> // 为了用 max

using namespace std; //省去敲代码时无数次敲打std::    比如：std::cout 或 std::vector

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        // 初始化 假设第一个元素就是最大的
        int max_sum = nums[0];
        int cur_sum = 0;

        for(int num : nums) //大白话翻译：对于 nums 里面的每一个元素，我都把它拿出来，叫做 num，然后执行下面的代码
        {
            // 如果当前累计大于0 说明对后面有增益 则继续加
            if (cur_sum > 0)
            {
                cur_sum += num;
            }
            // 否则 立刻抛弃当前累计和
            else
            {
                cur_sum = num;
            }

            //把加完当前数字的累计和与历史最大累计和比较 更新历史最大累计和
            max_sum = max(max_sum , cur_sum);
        }
        return max_sum;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {-2, 1 ,-3, 4 , -1 ,2 ,1, -5, 4};
    cout<< "nums1最大子数组和为：" << s.maxSubArray(nums1) <<endl;

    vector<int> nums2 = {5, 4 ,-1, 7 , 8};
    cout<< "nums2最大子数组和为：" << s.maxSubArray(nums2) <<endl;
}