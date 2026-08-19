/*2.6 字符串型 用于表示一串字符 两个表示风格如下：
1.C风格字符串：char 变量名 [] = "字符串值"
2.C++风格字符串：string 变量名 = "字符串值"
用的都是双引号
*/
#include <iostream>
using namespace std;
int main()
{
    char a [] = "hi nihao";//C风格字符串
    cout << a << endl;
    //C++风格字符串 旧版本需要一个头文件 #include <string> 现在不需要了
    string b = "wohenhao";
    cout << b << endl;
    string c = "1234wo";
    cout << c << endl;
    string d = "1234_wo";
    cout << d << endl;
    string e = "1234_我";
    cout << e << endl;
    return 0;
}