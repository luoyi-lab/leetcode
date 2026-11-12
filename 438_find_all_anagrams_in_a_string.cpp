/* 找到字符串中所有的字母异位词 完整题目：
给定两个字符串 s 和 p，找到 s 中所有 p 的异位词的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
异位词 指由相同字母重排列形成的字符串（包括相同的字符串）

示例 1：
输入: s = "cbaebabacd", p = "abc"
输出: [0, 6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词

示例 2：
输入: s = "abab", p = "ab"
输出: [0, 1, 2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词

和昨天的思路一模一样 不过今天是要找全
解法依然是定长滑动窗口 + 数组哈希表，只不过这次不是找到一个就停，而是要一直滑到尽头，把所有的结果都存进 vector 里
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)   // 定义函数，传入长串 s 和短串 p，返回一个整数数组
    {
        vector<int> result;   // 准备一个空数组，用来装所有找到的起始索引
        // 如果s比p还短 绝对找不到 直接返回空数组
        if(s.length() < p.length()) return result;

        vector<int> p_count(26, 0);  // p的指纹
        vector<int> s_count(26, 0);  // 滑动窗口的指纹

        // 1. 初始化 统计p的字母以及s最开头的窗口
        for(int i = 0; i < p.length(); i++)
        {
            p_count[p[i] - 'a']++;
            s_count[s[i] - 'a']++;
        }

        // 2.检查第一个窗口 起始索引为0 是不是异位词
        if(p_count == s_count)
        {
            result.push_back(0);   // push_back是尾部追加
        }

        // 3.开始滑动窗口
        // right是新加入窗口的字符索引
        for(int right = p.length(); right < s.length(); right++)
        {
            // 进入一个 新字符加入窗口
            s_count[s[right] - 'a']++;
            // 出去一个 窗口最左边的字符移出
            int left = right - p.length();
            s_count[s[left] - 'a']--;

            // 4.如果当前窗口的指纹和p的指纹相同 记录当前窗口的起始索引
            if(p_count == s_count)
            {
                // 当前窗口的起始索引 就是刚刚被移出去的那个字符的下一个位置
                result.push_back(left + 1);
            }
        }
        return result;

    }
};

int main() {
    Solution sol;
    
    // 示例 1
    string s1 = "cbaebabacd", p1 = "abc";
    vector<int> res1 = sol.findAnagrams(s1, p1);
    cout << "示例1: [";
    for (int i = 0; i < res1.size(); i++) cout << res1[i] << (i == res1.size()-1 ? "" : ", ");
    cout << "]" << endl; // 期望: [0, 6]

    // 示例 2
    string s2 = "abab", p2 = "ab";
    vector<int> res2 = sol.findAnagrams(s2, p2);
    cout << "示例2: [";
    for (int i = 0; i < res2.size(); i++) cout << res2[i] << (i == res2.size()-1 ? "" : ", ");
    cout << "]" << endl; // 期望: [0, 1, 2]

    return 0;
}