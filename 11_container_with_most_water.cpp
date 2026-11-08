/*盛最多水的容器 完整题目
给定一个长度为 n 的整数数组 height。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i])。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
说明：你不能倾斜容器

思路：木桶效应 一个木桶能装多少水 取决于比较短的那根木板
初始状态：把左指针left放在最左边 右指针right放在最右边 此时宽度最大
计算面积：面积 = 宽度×左右两根柱子中比较矮的那一根
如何移动：永远只移动比较矮的那根柱子
因为如果当你移动高柱子 宽度变小了 整体面积仍受限于矮柱子 只有可能变小 不会变大 只有移动矮柱子 才有可能在宽度变小的情况下实现面积变大
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while(left < right)
        {
            // 1.计算当前面积
            int width = right - left;
            int h = min(height[left], height[right]);  // 取最短的木板
            int current_area = width * h;

            // 2.更新最大面积
            max_area = max(current_area, max_area);

            // 3.移动较短的那根柱子
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }       
        }
        return max_area;
    }
};

int main()
{
    Solution s;
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "示例1最大水量：" << s.maxArea(height1) <<endl;

    vector<int> height2 = {1, 1};
    cout << "示例2最大水量： " << s.maxArea(height2) << endl;

    return 0;
}