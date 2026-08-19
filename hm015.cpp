/*2.8 数据的输入 用于从键盘获取数据
关键字：cin
语法：cin >> 变量
*/
#include <iostream>
using namespace std;
int main()
{
    //1.整型
    int a = 0;
    cout <<"请你给a赋值：" << endl;
    cin >> a;
    cout << "a的数值被你设定为：" << a << endl;
    //2.浮点型
    float b = 3.889f;
    cout <<"请你给b赋值：" << endl;
    cin >> b;
    cout << "b的数值被你设定为：" << b << endl;
    //3.字符型
    char c = 'q';
    cout <<"请你输入c：" << endl;
    cin >> c;
    cout << "c被你设定为：" << c << endl;
    //4.字符串型
    string d = "ahhhg";
    cout <<"请你输入d：" << endl;
    cin >> d;
    cout << "d被你设定为：" << d << endl;
    //5.布尔型
    bool e = true;
    cout <<"请你输入e：" << endl;
    cin >> e;
    cout << "e被1你设定为：" << e << endl;//这里只要输入非0的数字，都输出1，只有输入0或非数字，则输出0
    return 0;
}