/*4.1.2 struct 和 class区别
C++中，struct和class唯一的区别就是 默认的访问权限不同
区别：
  struct 默认权限为公共
  class 默认权限为私有
*/
#include <iostream>
using namespace std;
#include <string>

class C1
{
    int m_A;//默认权限是私有
};

struct C2
{
    int m_B;//默认权限是公共
};


int main()
{
    C1 c1;
    //c1.m_A; 不可访问
    C2 c2;
    c2.m_B = 100;//可以访问
    
    return 0;
}