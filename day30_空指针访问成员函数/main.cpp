#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    int m_Age;
    string m_Name;
   // Person(int age, string name)
   // {
   //     m_Age = age;
   //     m_Name = name;
   // }
    void showPerson(){
        if (this == NULL){
            return;
        };
        cout << "这个人的名字为：" << m_Name << endl;
        cout << "这个人的年龄为：" << m_Age << endl;
    };
};

int main(){
    Person *p = NULL;
    p->showPerson();
    return 0;
}