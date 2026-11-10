/* 长度最小的子数组 完整题目：
给定一个含有 n 个正整数的数组和一个正整数 target
找出该数组中满足其总和大于等于 target 的长度最小的子数组 [numsl, ..., numsr]，
并返回其长度。如果不存在符合条件的子数组，返回 0

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0

思路 毛毛虫吃叶子：
一条毛毛虫 头（right）在前面疯狂吃数字
每吃一个数字 就加到当前的总和sum里面
如果sum大于等于target 说明目前的窗口符合了 记录一下当前窗口的长度
为了寻求最短长度 毛毛虫的尾巴left得往前缩 把最左边的数字吐出来 sum减去最左边的数字 看sum是否还满足 sum >= target。如果能，就继续变得更短
*/
#include <iostream>
#include <vector>
#include <climits> // 包含 INT_MAX
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left = 0;
        long long sum = 0;  // sum可能会很大 用longlong防止溢出
        int min_len = INT_MAX;  //  初始最短长度设为无穷大

        // right作为毛毛虫头部 一路向前吃
        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right]; // 吃数字 加进sum里面

            // 只要当前总和 >= target 说明满足了条件，尝试缩尾巴    
            while(sum >= target)
            {
                // 更新最短长度：当前窗口的长度是 right - left + 1
                min_len = min(min_len, right-left+1);

                // 尾巴吐出一个数字，并且left向前走
                sum -= nums[left];
                left++;
            }
        }

        // 如果 min_len 还是初始值，说明整个数组加起来都不到 target
        return min_len == INT_MAX ? 0 : min_len;
        // 条件 ? 结果A : 结果B
        // 如果条件成立（True），就返回结果 A。
        // 如果条件不成立（False），就返回结果 B
        // 三目运算符完全等同于下面：
        /*
        if (min_len == INT_MAX) 
        {
             return 0;           // 没找到，返回0
        } 
        else
        {
            return min_len;     // 找到了，返回记录的最短长度
        }
        */
    }
};

int main() {
    Solution s;
    
    // 示例 1
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    cout << "示例1: " << s.minSubArrayLen(7, nums1) << endl; // 期望 2

    // 示例 2
    vector<int> nums2 = {1, 4, 4};
    cout << "示例2: " << s.minSubArrayLen(4, nums2) << endl; // 期望 1

    // 示例 3
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "示例3: " << s.minSubArrayLen(11, nums3) << endl; // 期望 0

    return 0;
}