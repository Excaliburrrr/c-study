#include <iostream>
using namespace std;

class Person
{
public:
    int m_Age;
    int *m_Height;
    //无参（默认）构造函数
    Person()
    {
        cout << "无参构造函数！" << endl;
    };
    //有参构造函数
    Person(int age, int height)
    {
        cout << "有参构造函数!" << endl;
        m_Height = new int(height);
        cout << m_Height << endl;
        m_Age = age;
    }; 
    Person(const Person &p)
    {
        cout << "拷贝构造函数!" << endl;
        m_Age = p.m_Age;
        //深拷贝，重新在堆区创建内存!
        m_Height = new int(*p.m_Height);
    }
    //析构代码，将堆区开辟的数据做释放
    ~Person(){
        if(m_Height != NULL)
        {
            cout << "析构函数，释放堆区内存！" << endl;
            delete m_Height;
            //防止野指针的出现，将其置空
            m_Height = NULL;
        }
    } 
};

int main(){
    //p1, p2都放在栈区，满足先进后出，p2先被释放
    Person p1(18, 180);
    cout << "p1年龄：" << p1.m_Age << "\t" << "p1身高：" << *p1.m_Height << endl;
    //如果利用编译器提供的拷贝构造函数，会做浅拷贝操作
    //浅拷贝带来的问题就是内存的重复释放！！
    //浅拷贝的问题要利用深拷贝来进行解决
    Person p2(p1);
    cout << "p2年龄：" << p1.m_Age << "\t" << "p2身高：" << *p1.m_Height << endl;

}