#include <iostream>
using namespace std;

//左移运算符重载

class Data
{
public:
    int m_A;
    int m_B;

    Data(int, int);
    
    //无法利用成员函数实现左移运算符重载，因为无法使得cout在左侧
    ostream& operator<<(ostream& cout)
    {
        cout << "m_A = " << this->m_A << endl;
        cout << "m_B = " << this->m_B << endl;
    }
    
};

Data::Data(int a, int b)
{
    m_A = a;
    m_B = b;
}

//重载左移运算符
ostream& operator<<(ostream& cout, Data &d)
{
    cout << "m_A = " << d.m_A << endl;
    cout << "m_B = " << d.m_B << endl;
    return cout;
}

void test01(){
    Data d1(10, 100);
    cout << d1 << endl;
    //使用成员函数实现的左移运算符重载无法实现cout在左侧
    d1 << cout;
}

int main(){
    test01();
    return 0;
}

