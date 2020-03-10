#include <iostream>
using namespace std;

//加号运算符重载


class Data
{
public:
    int m_A, m_B;
    Data(){};
    Data(int a, int b);
 //   Data operator+(Data &d);
};

Data::Data(int a, int b)
{
    m_A = a;
    m_B = b;
}
//1、成员函数重载加号
//Data Data::operator+(Data &d)
//{
//    Data temp;
//    temp.m_A = d.m_A + this->m_A;
//    temp.m_B = d.m_B + this->m_B;
//    return temp;
//};

//2、全局函数重载加号
Data operator+(Data &d1, Data &d2)
{
    Data temp;
    temp.m_A = d1.m_A + d2.m_A;
    temp.m_B = d1.m_B + d2.m_B;
    return temp;
}

//运算符重载也可以发生函数重载
Data operator+(Data &d, int num)
{
    Data temp;
    temp.m_A = d.m_A + num; 
    temp.m_B = d.m_B + num; 
    return temp;
}
//左移运算符重载
ostream& operator<<(ostream &cout, Data &d)
{
    cout << "m_A = " << d.m_A << "\t" << "m_B = " << d.m_B;
    return cout; //链式编程思想
}

//递增运算符重载
class MyInteger
{
public:
    MyInteger(){};

private:
    int m_Num;
    
};

MyInteger::MyInteger(){
    m_Num = 0;
}
void test01()
{
    Data d1(10, 20);
    Data d2(30, 40);
    Data d3 = d1 + d2;
    Data d4 = d3 + 10;
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    cout << d4 << endl;
    //cout << d3.m_A << endl;
    //cout << d3.m_B << endl;
    //cout << d4.m_A << endl;
    //cout << d4.m_B << endl;
}

int main()
{
    test01();
    return 0;
}