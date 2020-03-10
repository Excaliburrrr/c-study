#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    //静态成员变量：类内声明，类外初始化
    static string  m_type;
    //静态成员函数
    static void func(){
        cout << "物种为： " << m_type << endl;
    }
};
string Person::m_type = "灵长类动物";

void test(){
    //静态成员函数有两种访问方式
    //１、通过对象访问
    Person p;
    //２、通过类名访问
    p.func();
    Person::func();
}

int main(){
    test();
    return 0;
}