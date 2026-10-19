// 删除有序数组中的重复项
// 例如： 输入：nums = [1,1,2]
//       输出：2，且 nums 前两个元素变成 [1,2]
// 要求原地修改，不能用额外数组
// 思考 要求原地修改 就不能新建一个空的数组 遇到不重复的就塞进数组里面
// 要用到双指针：     这里的指针 不是 C++ 里那种存储内存地址的底层指针（int* p）  而是两个用来标记位置（数组下标）的索引
// fast：负责去前面探路
// slow：跑得慢，它始终指着“当前已经整理好的、不重复区域的最后一个位置”
// 假设数组是 nums = [1,1,2,2,3]
// 初始状态：
// slow = 0(指向第一个1)
// fast = 1(指向第二个1)
// 第一步 fast指向1 slow也指向1 重复 不用管 fast继续向前
// 第二步 fast指向2 slow指向1 有不同 
//   此时slow向前走一步 来到索引1
//   把fast指向的数字2 塞到现在slow的位置 数组变成了[1，2，2，2，3]
// 第三步 fast继续前进 指向2 不变
// 第四步 fast继续向前 指向3 有不同 变 
//   slow先向前一位 来到索引2 
//   fast指向的3塞入到当前slow的位置 数组变为[1,2,3,2,3]
// 结束 fast走到头了 slow停在不重复的最后一个位置 slow 数字总长度为slow + 1 = 3 即[1,2,3]为所求
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> & nums)
    {
        if (nums.empty())
        {
            return 0;
        } //必须要先判空

        int slow = 0;
        for(int fast = 1 ; fast < nums.size() ; fast++)
        {
            if(nums[fast] != nums[slow])
            {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};


int main()
{
    Solution S;
    vector<int> nums1 = {1,1,2,3,3};
    int len1 = S.removeDuplicates(nums1);
    cout << "返回长度为：" << len1 <<endl;
    for (int i = 0 ; i < len1 ; i++)   //i < len1 因为第一个下标为0
    {
        cout << nums1[i] <<" ";
    }

    vector<int> nums2 = {1,1,2,3,4,6,7,8,8};
    int len2 = S.removeDuplicates(nums2);
    cout << "返回长度为：" << len2 <<endl;
    for (int j = 0 ; j < len2 ; j++)   
    {
        cout << nums2[j] <<" ";
    }
}