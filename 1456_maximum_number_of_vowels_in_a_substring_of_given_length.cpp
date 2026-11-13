/* 定长字串中元音的最大数目 完整题目：
给你字符串 s 和整数 k。
请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
英文中的元音字母为（a, e, i, o, u）

示例 1：
输入：s = "abciiidef", k = 3
输出：3
解释：子字符串 "iii" 包含 3 个元音字母

示例 2：
输入：s = "aeiou", k = 2
输出：2
解释：任意长度为 2 的子字符串都包含 2 个元音字母

示例 3：
输入：s = "leetcode", k = 3
输出：2
解释："lee"、"eet" 和 "ode" 都包含 2 个元音字母

思路：
先框住最前面的 k 个字母，数一数里面有几个元音（a, e, i, o, u）。
窗户开始往右滑：
右边进一个：如果新进来的是元音，总数 +1。
左边出一个：如果被踢出去的是元音，总数 -1。
每滑一步，就记录一下历史最高人数。
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
    // 辅助函数：判断是不是元音字母
    bool isVowel(char c)
    {
        // 只要其中有一个条件成立，整个表达式就成立（返回 true）
        return c == 'a' || c == 'e' || c== 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k)
    {
        int current_vowels = 0;

        // 1.先看开头的k长度窗口
        for(int i = 0; i < k; i++)  
        {
            if(isVowel(s[i]))  //把 s[i] 丢进 isVowel，内部会自动去比对那 5 个元音字母，然后直接吐出 true 或 false
            {
                current_vowels++;
            }
        }

        int max_vowels = current_vowels;

        // 2.窗口开始滑动
        for(int right = k; right < s.length(); right++)
        {
            // 右边进
            if(isVowel(s[right]))
            {
                current_vowels++;
            }

            // 左边出
            int left = right - k;
            if(isVowel(s[left]))
            {
                current_vowels--;
            }

            // 3.更新历史最大值
            max_vowels = max(max_vowels, current_vowels);

            // 4.如果当前最大值已经等于 k 了，不可能更大了，直接返回
            if(max_vowels == k) return k;
        }

        return max_vowels;
    }
};

int main() {
    Solution sol;
    
    cout << "示例1: " << sol.maxVowels("abciiidef", 3) << endl; // 期望 3
    cout << "示例2: " << sol.maxVowels("aeiou", 2) << endl;     // 期望 2
    cout << "示例3: " << sol.maxVowels("leetcode", 3) << endl;  // 期望 2

    return 0;
}