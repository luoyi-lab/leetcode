/* 无重复字符的最长字串 完整题目：
给定一个字符串 s，请你找出其中不含有重复字符的 最长子串 的长度

示例 1：
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2：
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3：
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是【子串】的长度，"pwke" 是一个子序列，不是子串

思路：
想象你有一条毛毛虫（窗口），在字符串上从左往右爬。
尾巴（左指针 left）：如果发现前面有重复的字母，尾巴就往前缩，直到把重复的字母排出去。
头（右指针 right）：一直往前探路，把新字母吃进来。
窗口长度：就是 right - left + 1。我们只需要记录这个窗口在爬行过程中的最大长度。
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)  // 传入一个字符串 返回一个整型
    {
        // 哈希表 记录字符最后一次出现的索引（这个索引是人为定义的）
        unordered_map<char, int> last_pos;  //   键值对  char是字符
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++)
        {
            char current_char = s[right];

            // 如果这个字符之前出现过 且它的位置在当前窗口内
            if(last_pos.find(current_char) != last_pos.end() && last_pos[current_char] >= left)  // find是在哈希表里面查字符 如果没找到返沪end() 这里 !=last_pos.end() 就是代表找到了
            //last_pos[current_char] >= left 保证字母确实在目前滑动的窗口内
            {
                // 左指针直接跳到重复字符的下一个位置
                left = last_pos[current_char] + 1;
            }
            //更新该字符最后出现的位置为right
            last_pos[current_char] = right;

            // 更新最大长度
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main()
{
    Solution s;
    cout << "示例1: " << s.lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << "示例2: " << s.lengthOfLongestSubstring("bbbbb") << endl;    // 1
    cout << "示例3: " << s.lengthOfLongestSubstring("pwwkew") << endl;   // 3
    return 0;
}