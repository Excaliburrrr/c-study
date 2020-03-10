#include <iostream>
using namespace std;


// 公共继承
class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};


class Son:public Base1
{
public:
    void func()
    {
        m_A = 10; //父类中公共权限成员 到子类中依然是公共权限
        m_B = 10; //父类中保护权限成员 到子类中依然是保护权限
        //m_C = 10; //父类中私有权限成员 子类无法访问
    }
    int m_D;

};

void test01()
{
    cout << "size of son = " << sizeof(Son) << endl;
}

int main(){
    test01();
    return 0;
}
