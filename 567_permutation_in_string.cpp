/* 字符串的排列 完整题目：
给你两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true；否则，返回 false。
换句话说，s1 的排列之一是 s2 的子串

示例 1：
输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba")

示例 2：
输入：s1 = "ab" s2 = "eidboaoo"
输出：false

思路：这道题是滑动窗口和数组哈希表的组合
简单说：你要在 s2 中找一段连续的子串，它的长度必须等于 s1，且里面每个字符出现的次数和 s1 完全一致
1.用一个大小固定的s1.length() 的窗户 套在s2上
2.先统计出s1里每个字母的数量
3.窗户在s2上从左往右滑
 进一个：新进入窗户的字母，计数 +1。
 出一个：被挤出窗户的旧字母，计数 -1。
4.每次滑动后，对比一下“窗户里的字母计数”和“s1 的字母计数”是不是完全一样。如果一样，说明找到了排列，返回 true
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // 如果s1比s2还长 那不可能包含 直接判false
        if(s1.length() > s2.length()) return false;

        // 两个数组当哈希表 记录26个字母出现的次数
        vector<int> count1(26, 0);  // 记录s1字母出现的次数   26个数值 每个都是0
        vector<int> count2(26, 0);  // 记录滑动窗口里的字母次数
        
        // 1.初始化：统计s1的所有字母 以及s2的前s1.length() 个字母
        for(int i = 0; i < s1.length(); i++)
        {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        // 2.初始窗口先对比一次
        if(count1 == count2)return true;

        // 3.开始滑动窗口
        // right 是新加入窗户的字母索引 left是被踢出窗户的字母索引
        for(int right = s1.length(); right < s2.length(); right++)
        {
            int left = right - s1.length(); // 左侧被踢出的索引

            // 进一个：新字符加入窗口
            count2[s2[right] - 'a']++;
            // 出一个：旧字符离开窗口
            count2[s2[left] - 'a']--;

            // 每次滑动后，对比一下当前的窗口与s1是否匹配
            if(count1 == count2) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << "示例1: " << boolalpha << s.checkInclusion("ab", "eidbaooo") << endl; // true
    cout << "示例2: " << boolalpha << s.checkInclusion("ab", "eidboaoo") << endl; // false
    return 0;
}