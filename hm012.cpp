/*2.5 转义字符 用于表示一些不能显示出来的ASCII字符 常用如下：
\a 警报
\n 换行（LF），将当前位置移到下一行开头
\t 水平制表（HT），跳到下一个TAB位置
\\ 代表一个反斜线字符‘\’
*/
#include <iostream>
using namespace std;
int main()
{
    //换行：\n
    cout << "hello word\nhello"<< endl;
    //水平制表：\t
    cout << "aaaa\tbbbb" << endl;//\t总共占8个字符位置  在此处也就是aaaa后面有4个空格
    cout << "aaa\tbbbb" << endl;
    cout << "aa\tbbbb" << endl;//可以清晰的看到输出中上下行b的初始位置是对齐的，比较整齐的输出后面的内容
    cout <<"\\" << endl; //  用处就是输出一个反斜杠
    return 0;
}