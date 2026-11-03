/* 有效的字母异位词 题目描述：
给定两个字符串 s 和 t，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

示例 1：
输入: s = "anagram", t = "nagaram"
输出: true

示例 2：
输入: s = "rat", t = "car"
输出: false

约束条件：
1.s 和 t 仅包含小写英文字母 → 🔑 这是最关键的约束：只有 26 种字符，可以直接开一个长度 26 的数组当哈希表，比 unordered_set 快得多
2.长度最长 5 × 10^4 → O(n log n) 的排序法也能过，但 O(n) 计数更好

“哈希表”是一种思想，而 unordered_set 只是官方提供的一个通用工具

思路：
用一个长26的数组当计数器 一开始所有字母的计数器都是0 遍历 s 时 对应的字母的计数器加1；遍历t时 对应的字母的计数器减1 
如果最后所有的计数器都是0 说明完全抵消 是异位词
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 如果长度不一样 一定不是异位词
        if(s.length() != t.length())
        {
            return false;
        }

        // 创建一个长度为26的数组 初始全为0
        // 下标 0 代表 a 下标 1 代表 b，以此类推
        int record[26] = {0};  // 创建一个全为0的数组

        // 1.统计s中每个字符出现的个数
        for(size_t i = 0; i < s.length(); i++)   // 下标 / 长度 / 计数	 用 size_t（或 auto）
        {
            record[s[i] - 'a']++;
            // 小写字母 'a' 的 ASCII 码是 97，'b' 是 98，'c' 是 99，以此类推，'z' 是 122。
            // 如果当前字母是 'a'：'a' - 'a' = 97 - 97 = 0。
            // 如果当前字母是 'b'：'b' - 'a' = 98 - 97 = 1。 以此类推
        }

        // 2.在t中消耗这些次数
        for(size_t j = 0; j < t.length(); j++)
        {
            record[t[j] - 'a']--;

            // 优化：如果发现有负数 说明t里某个字母比s中的要多 直接返回false
            if (record[t[j] - 'a'] < 0)
            {
                return false;
            } 
        }
        return true;   // 为什么不用判断s中某个字母比t中某个相同字母多？因为如果有字母多 必定有另外字母少 直接触发负数判false
    }
};

int main()
{
    Solution s;
    cout << "示例1：" << boolalpha << s.isAnagram("anagram", "nagaram") <<endl;   // true
    cout << "示例2: " << boolalpha << s.isAnagram("rat", "car") << endl;       // false
    
    return 0;
}