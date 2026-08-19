/*2.4 字符型 用于显示单个字符 语法：char ch = 'a'
注意用单引号 且单引号内只能是一个字符，不能是字符串，比如abcdf
只占用1个字节
*/
#include <iostream>
using namespace std;
int main()
{
    char ch = 'a';
    cout << "char类型所占字节为" << sizeof( char ) << endl;
    cout << "ch所占字节为" << sizeof( ch ) << endl;
    cout << ch << endl;
    //字符型变量对应ASCII编码，内存存放对应是ASCII编码的数字
    cout << (int)ch <<endl;//endl 表示输出换行
    return 0;
}