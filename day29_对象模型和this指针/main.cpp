#include <iostream>
using namespace std;

class Person{
public:
    int age; //非静态成员变量，属于类的对象上
    int static m_B; //静态成员变量，不属于类的对象上
    Person(int age){
        // this 指针指向被调用的成员函数所属的对象
        this -> age = age;
    }; //非静态成员函数，不属于类的对象上
    static void func1(){} //静态成员函数，不属于类的对象上
    Person& PersonAddAge(Person &p)
    {
        this -> age += p.age;
        //this 指向p2的指针，而*this指向的就是p2这个对象本体
        return *this;
    }

};
int Person::m_B = 10;


void test01(){
    Person p(10);
    Person p1(p);
    p1.PersonAddAge(p).PersonAddAge(p).PersonAddAge(p);
    cout << p1.age << endl;
    //空对象占用内存为：１
    //C++编译器会给每个空对象也分配一个内存空间，是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout << sizeof(p) << endl;
}

int main(){
    test01();
    return 0;
}