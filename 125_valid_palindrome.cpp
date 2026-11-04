/* 验证回文串 题目描述：
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样，则可以认为该短语是一个回文串。
字母和数字都属于字母数字字符。
给你一个字符串 s，如果它是回文串，返回 true；否则，返回 false。

示例 1：
输入: s = "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串。

示例 2：
输入: s = "race a car"
输出: false
解释："raceacar" 不是回文串。
示例 3：

输入: s = " "
输出: true

思路：不创建任何新的字符串，双指针，直接在原字符串上左右开弓。左指针往右走，右指针往左走，遇到非字母数字就跳过。
*/
#include <iostream>
#include <string>
#include <cctype> // 包含 isalnum(判断是不是字母或数字) 和 tolower(转小写)

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;    // left站在字符串最左边 
        int right = static_cast<int>(s.length()) - 1;   // right站在最右边

        while(left < right)
        {
            // 1. 左指针遇到非字母数字 跳过
            while (left < right && !isalnum(s[left])) //如果 s[left] 不是字母或数字（比如是空格、逗号），left 就往右走一格
            {
                left++;
            }

            // 2.右指针遇到非字母数字 跳过
            while (left < right && !isalnum(s[right]))  ////如果 s[right] 不是字母或数字（比如是空格、逗号），right 就往左走一格
            {
                right--;
            }

            // 3.比较两端的字符 （统一转小写比较）
            if(tolower(s[left]) != tolower(s[right])) 
            {
                return false;  // 发现不对直接判false  这里不用担心两边速度不一样 因为排完雷 两者一定是对齐的
            }

            // 4.如果相等，左右指针向中间靠拢一步，准备比对下一对
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // 测试用例 1
    string s1 = "A man, a plan, a canal: Panama";
    cout << "输入: \"" << s1 << "\"" << endl;
    // boolalpha 用于让 cout 打印出 true/false，而不是 1/0
    cout << "输出: " << boolalpha << sol.isPalindrome(s1) << endl; 

    // 测试用例 2
    string s2 = "race a car";
    cout << "输入: \"" << s2 << "\"" << endl;
    cout << "输出: " << boolalpha << sol.isPalindrome(s2) << endl;

    // 测试用例 3 (坑点测试)
    string s3 = " ";
    cout << "输入: \"" << s3 << "\"" << endl;
    cout << "输出: " << boolalpha << sol.isPalindrome(s3) << endl;

    return 0;
}