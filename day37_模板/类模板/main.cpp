#include <iostream>
#include <string>
using namespace std;

//类模板的成员函数创建时机

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};


class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};


template <class T>
class MyClass
{
public:
    T obj;

    //类模板中的成员函数
    void func1()
    {
        obj.showPerson1();
    }
    void func2()
    {
        obj.showPerson2();
    }
};


int main()
{
    MyClass<Person1> mc;
    mc.func1();
    return 0;

}