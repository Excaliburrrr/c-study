#include <iostream>
using namespace std;

class MyInt
{
    friend ostream& operator<<(ostream&, MyInt);
public:
    MyInt(int);
    //前置递增
    MyInt& operator++();
    //后置递增
    MyInt operator++(int);

private:
    int m_Num;
};

MyInt::MyInt(int a)
{
    m_Num = a;
}
MyInt& MyInt::operator++()
{
    m_Num++;
    return *this;
}

MyInt MyInt::operator++(int)
{
    //先记录当时结果
    MyInt temp = *this;
    //后递增
    m_Num++;
    //最后返回记录结果
    return temp;
}

//重载左移运算符
ostream& operator<<(ostream& cout, MyInt a)
{
    cout << a.m_Num << endl;
    return cout;
}

void test01()
{
    MyInt a(10);
    cout << a << endl;
    cout << ++a << endl;
    cout << a << endl;
    cout << a++ << endl;
    cout << a << endl;
}

int main()
{
    test01();
    return 0;
}