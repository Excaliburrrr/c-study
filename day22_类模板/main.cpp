#include <iostream>
using namespace std;

template<typename T>
class Person{

public:
    Person(T id, T age){
        this -> mAge = age;
        this -> mId = id;
    }
    void Show(){
        cout << "ID: " << mId << "\t" << "Age: " << mAge << endl;
    }

public:
    T mId;
    T mAge;
};

int main()
{
    //函数模板在调用的时候，可以自动类型推导；
    //类模板必须显式地指定类型；
    Person<int> p(10, 20);
    p.Show();
    return 0;
}