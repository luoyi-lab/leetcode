/* 移动零 完整题目：
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意，必须在不复制数组的情况下原地对数组进行操作。

示例 1：
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2：
输入: nums = [0]
输出: [0]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int slow = 0;  // 慢指针 指向下一个要填入非零数字的位置

        // fast指针往前走，寻找非零数字
        for(int fast = 0; fast < nums.size(); fast++)
        {
            if(nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                slow++;  // slow向前走       
            }
        }
        // 遍历结束之后 slow后面的位置全填0
        for(int i = slow; i < nums.size(); i++)
        {
        nums[i] = 0;
        }
    }
};

// 辅助打印函数
void printNums(const vector<int>& nums)
{
    cout << "[";
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if(i != nums.size() - 1) cout << ",";
    } 
    cout << "]";
}

int main()
{
    Solution s;

    // 示例 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    cout << "输入: ";
    printNums(nums1);
    s.moveZeroes(nums1);
    cout << "输出: ";
    printNums(nums1); // 期望: [1, 3, 12, 0, 0]
    cout << "-------------------" << endl;

    // 示例 2
    vector<int> nums2 = {0};
    cout << "输入: ";
    printNums(nums2);
    s.moveZeroes(nums2);
    cout << "输出: ";
    printNums(nums2); // 期望: [0]

    return 0;
}