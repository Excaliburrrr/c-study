#include <iostream>
using namespace std;

//拷贝构造函数的调用时机


class Person
{
public:
    Person(){
        cout << "Person默认构造函数调用" << endl;
    }
    Person(int age)
    {
        m_Age = age;
        cout << "Person有参构造函数调用" << endl;
    }
    Person(const Person& p)
    {
        m_Age = p.m_Age;
        cout << "Person拷贝构造函数调用" << endl; 
    }
    ~Person(){
        cout << "Person析构函数调用" << endl;
    }
public:
    int m_Age;
};

void doWork(Person p)
{
    cout << p.m_Age << endl;
    p.m_Age = 1000;
    cout << p.m_Age << endl;
}

int main()
{
    Person p1(20);
    doWork(p1);
    cout << p1.m_Age << endl;
    return 0;

}