#include <iostream>
using namespace std;

class Person
{
public:
    int m_age;
    //普通构造函数
    //默认(无参)构造函数
    Person(int age)
    {
        m_age = age;
        cout << "age = " << age << endl;
        cout << "Person的构造函数" << endl;
    };
    ~Person()
    {
        cout << "Person的析构函数" << endl;
    };
    Person (const Person &p){
        m_age = p.m_age;
    }
};

int main(){
    Person p1(22);
    //显示法调用拷贝构造
    Person p2 = Person(p1);
    return 0;
}
