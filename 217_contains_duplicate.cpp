/* 存在重复元素  题目描述：
给你一个整数数组 nums。如果任一值在数组中出现至少两次，返回 true；如果数组中每个元素互不相同，返回 false

示例 1：
输入：nums = [1,2,3,1]
输出：true

示例 2：
输入：nums = [1,2,3,4]
输出：false

示例 3：
输入：nums = [1,1,1,3,3,4,3,3,3]
输出：true

补充回忆知识
假设你按这个顺序插入数据：5, 1, 3

① 数组 vector     单次操作速度：拖拉机速度 O(n) 只能从0挨个看过去

vector<int> v = {5, 1, 3};
遍历：5 1 3 （保留你的插入顺序）
你可以用 v[0] 拿到 5，用 v[1] 拿到 1。

② 哈希表 unordered_set（无序）   单次操作速度：火箭速度 O(1)

unordered_set<int> us = {5, 1, 3};
遍历：3 5 1 （顺序完全随机，取决于哈希函数）
你绝对不能写 us[0] ！

③ 红黑树 set（有序）   单次操作速度：飞机速度 O(logn)
set<int> s = {5, 1, 3};
遍历：1 3 5 （自动从小到大排好了！）
你绝对不能写 s[0] ！只能顺着迭代器从第一个拿。

到底该怎么选：

只要速度，不要顺序 → 用哈希表。

既要快，又要顺序 → 用红黑树 set / map

数据不动，或者要随机访问 → 用 vector
*/

/*
方法一：哈希表法（时间复杂度 O(n)
核心逻辑：边遍历边记账。遇到一个数，去哈希表里查一下，如果已经有了，直接返回 true；如果没有，就把它记下来
*/
#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        // 建立一个哈希集合（超级储物柜）
        unordered_set<int> seen;
        
        for (int num : nums) 
        {
            // 如果柜子里已经有这个数，说明重复了
            if (seen.count(num) > 0) 
            {
                return true;
            }
            // 如果没找到，就把这个数存进柜子里
            seen.insert(num);
        }
        
        // 全部遍历完都没找到重复的
        return false;
    }
};



/*
方法二：排序法（时间复杂度 O(n logn)
核心逻辑：先把数组从小到大排好队。这样一来，如果有重复的数字，它们必定是挨在一起的
只需要顺着看一遍，看看有没有相邻的两个人长得一样就行了
*/
#include <iostream>
#include <vector>
#include <algorithm> // 包含 sort 函数

using namespace std;

class Solution2 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        // 1. 先对原数组进行排序（从小到大）
        sort(nums.begin(), nums.end());
        
        // 2. 遍历数组，检查相邻元素
        for (size_t i = 1; i < nums.size(); i++) 
        {
            // 如果当前数字和前一个数字相等，说明有重复
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        
        return false;
    }
};

int main() 
{

Solution1 s;
vector<int> nums1 = {1, 2, 3, 1};
vector<int> nums2 = {1, 2, 3, 4};
cout << "哈希表法 示例1: " << boolalpha << s.containsDuplicate(nums1) << endl;
cout << "哈希表法 示例2: " << boolalpha << s.containsDuplicate(nums2) << endl;

Solution2 s1;
vector<int> nums3 = {1, 2, 3, 1};
vector<int> nums4 = {1, 2, 3, 4};
cout << "排序法 示例3: " << boolalpha << s1.containsDuplicate(nums1) << endl;
cout << "排序法 示例4: " << boolalpha << s1.containsDuplicate(nums2) << endl;
return 0;
}