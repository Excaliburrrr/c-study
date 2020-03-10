#include <iostream>
using namespace std;

//设计一个原类，求圆的周长
double const PI = 3.14;

class Circle
{
    //访问权限
    //公共权限
public:
    //属性
    double m_r;

    //行为
    //获取圆的周长
    double cacLength()
    {
        return 2 * PI * m_r;
    };

    //访问权限
};

class Student
{
public:
    string mName, mID;

    void show()
    {
        cout << "学生的姓名为：" << mName << endl;
        cout << "学生的学号为：" << mID << endl;
    };
};


int main()
{
    //通过这个类创建一个具体的对象
    Circle c1;
    c1.m_r = 10;
    cout << "圆的周长为：" << c1.cacLength() << endl;
    Student s1;
    s1.mID =  "18S153728";
    s1.mName = "Vansikey"; 
    s1.show();


}