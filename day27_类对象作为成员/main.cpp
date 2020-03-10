#include <iostream>
#include <string>
using namespace std;


class Phone{
public:
    string m_PName;
    Phone(string Name){
        cout << "Phone的构造函数调用！" << endl;
        m_PName = Name;
    };
    ~Phone(){
        cout << "Phone的析构函数调用!" << endl;
    }
};

class Person
{
public:
    string m_Name;
    Phone m_Phone;
    Person(string name, string p): m_Name(name), m_Phone(p){
        cout << "Person的构造函数调用!" << endl;
    };
    ~Person(){
        cout << "Person的析构函数调用！" << endl;
    }
};

void test01(){
    Person p("张三", "iPhone X MAX"); 
    cout << p.m_Name << "拿着：" << p.m_Phone.m_PName << endl;
};

int main()
{
    test01();
    return 0;
}