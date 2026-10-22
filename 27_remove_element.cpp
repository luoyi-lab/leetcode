/* 27.移除元素 题目描述：
给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量
假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要
返回 k

示例1：输入：nums = [3,2,2,3], val = 3
       输出：2, nums = [2,2,_,_]
      解释：函数应该返回 k = 2，并且 nums 中的前两个元素均为 2。
      你在回到函数后，不需要考虑数组中超出新长度后面的元素。
示例2：输入：nums = [0,1,2,2,3,0,4,2], val = 2
       输出：5, nums = [0,1,4,0,3,_,_,_]
      解释：函数应该返回 k = 5，并且 nums 中的前五个元素为 0,1,3,0,4。
      注意这五个元素可为任意顺序。

以 nums = [3, 2, 2, 3] val = 3 为例 讲一下思路：
fast指针：在前面探路
slow指针：如果探路探到安全的 就负责收集
第一步 fast = 0 指向3 不要 fast向前  slow = 0 不动
第二步 fast = 1 指向2 要 fast继续向前 slow 也向前 slow =1 并且将0位置填入2 现在是[2,2,2,3]
第三步 fast = 2 指向2 要 fast继续向前 slow 也向前 slow = 2 并且将1位置填入2 现在是[2,2,2,3]
第四步 fast = 3 指向3 不要 结束       slow 不动  最终是 k = slow = 2  数组后面的元素是什么无所谓
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   int removeElement(vector<int> &nums, int val)
   {
    int slow = 0;

    for(int fast = 0 ; fast < nums.size() ; fast++)
    {
        if (nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }   // 这里不需要else因为当fast = val fast向前是for 里的操作 并且slow没有任何变化
    return slow; //输出安全元素的个数k
   }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    int res1 = s.removeElement(nums, 3);
    cout << "安全元素个数为：" << res1 <<endl;
    for(int i = 0 ; i < res1 ; i++)
    {
        cout << nums[i] << " " ;
    }

    return 0;
}
