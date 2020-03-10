#include <iostream>
using namespace std;

class Person{
public:
    int m_Age;
    //加上mutable后，在常函数中也能修改其值
    //同样加上mutable后在常对象中也能修改其值
    mutable int m_B;
    Person(){};
    //this指针的本质是指针常量，指针的指向是不可以修改的
    //但是指针指向的值是可以修改的
    //如果在成员函数后面加上const关键字相当于做了如下操作
    //const Person* this;
    //使得指针指向的值也不能修改！
    void show() const {
        //m_Age = 100;
        cout << m_Age << endl;
    }
};

int main()
{
    const Person p; //在对象前加const，变成常对象，并且常对象不许调用普通成员函数
    p.m_B = 100;
    return 0;
}