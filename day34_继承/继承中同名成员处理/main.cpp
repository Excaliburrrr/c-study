# include <iostream>
using namespace std;

class DataBase
{
public:
    int m_A;
    int m_B;
    DataBase()
    {
        m_A = 100;
        m_B = 100;
    }
    void func()
    {
        cout << "父类中的成员函数" << endl;
    }
    void func(int a)
    {
        cout << "父类中重载的成员函数" << endl;
    }

};

class Data1 :public DataBase
{
public:
    int m_A;
    int m_B;
    int m_C;
    Data1()
    {
        m_A = 200;
        m_B = 200;
        m_C = 50;
    }
    void func()
    {
        cout << "子类中的成员函数" << endl;
    }
};

void test01()
{
    //如果子类出现和父类中同名的成员函数或属性，
    //子类中的同名成员会隐藏掉父类中所有同名成员函数
    //如果想访问到父类中被隐藏的同名成员函数，需要加作用域 
    Data1 d;
    cout << "size of data1: " << sizeof(Data1) << endl;
    cout << "Data1 下的 m_A = " << d.m_A << endl;
    cout << "DataBase 下的 m_A = " << d.DataBase::m_A << endl;
    //调用子类中的成员函数
    d.func();
    //调用父类中的成员函数
    d.DataBase::func();
    //调用父类中重载的成员函数
    d.DataBase::func(100);
}

int main()
{
    test01();
    return 0;
}