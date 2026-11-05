/*两数之和II 完整题目：
给你一个下标从 1 开始的整数数组 numbers，该数组已按非递减顺序排列，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2]，则 1 <= index1 < index2 <= numbers.length。
以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
你所设计的解决方案必须只使用常量级的额外空间。

思路：
首先看到：只使用常量级的额外空间 这样就不能用哈希表 因为需要O(n)的空间
唯一的解法是左右双指针
一个指针left放在最左边 最小的数
一个指针right放在最右边 最大的数
1.把这两个数加起来
2.如果和小了 让left往右走一步
3.如果和大了 让right往左走一步
4.直到和为target 成功
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        // 只要左右指针没有相遇 就继续找
        while(left < right)
        {
            int sum = numbers[left] + numbers[right];

            if(sum == target)
            {
                // 题目要求下标从1开始 所以直接给left和right各自加1 构造一个下标从1开始的数组
                return{left + 1, right + 1};
            }
            else if(sum < target)
            {
                // 和小了 left向右移动
                left++;
            }
            else
            {
                // 和大了right向左移动
                right--;
            }
        }
        return{};  // 如果没找到返回空数组
    }
};

int main()
{
    Solution s;

    // 示例 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> res1 = s.twoSum(nums1, target1);
    cout << "示例1: [" << res1[0] << ", " << res1[1] << "]" << endl; // 期望: [1, 2]

    // 示例 2
    vector<int> nums2 = {2, 3, 4};
    int target2 = 6;
    vector<int> res2 = s.twoSum(nums2, target2);
    cout << "示例2: [" << res2[0] << ", " << res2[1] << "]" << endl; // 期望: [1, 3]

    return 0;
}