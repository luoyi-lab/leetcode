/*136. 只出现一次的数字  题目描述：
给你一个 非空 整数数组 nums，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

示例 1：输入：nums = [2,2,1]        输出：1
示例 2：输入：nums = [4,1,2,1,2]    输出：4
示例 3：输入：nums = [1]            输出：1

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        // 遍历数组中的每一个数字
        for ( int num : nums )  // 这种写法只关心数组里的数值 不关心下标 传统写法：for (int i = 0; i < nums.size(); i++) 是要关心下标的 或者说通过下标可以知道数值的情况
        {
            ans ^= num; //即 ans = ans ^ num 和+= *= 等是一样的意思
        }
        return ans;
    }
};


int main()
{
    Solution s;

    //测试1
    vector<int> nums1 = {2,2,3,3,4,4,1};
    cout << "示例1结果：" << s.singleNumber(nums1) <<endl;
    /*完整计算流程：
    0^2=2
    2^2=0
    0^3=3
    3^3=0
    0^4=4
    4^4=0
    0^1=1
    最后返回1，即结果
    */

    //测试2
    vector<int> nums2 = {4,2,3,3,4,1,1,5,5};
    cout << "示例2结果：" << s.singleNumber(nums2) <<endl;
}