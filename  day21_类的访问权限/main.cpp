#include <iostream>
using namespace std;


/*
1、public       公共权限    类内可以访问    类外可以访问
2、protected    保护权限    类内可以访问    类外不可访问    儿子可以访问父亲中的保护内容
3、private      私有权限    类内可以访问    类外不可访问    儿子不可访问 
*/


class Person
{
public:
    string m_Name; //姓名
    void func()
    {
      m_Name = "张三";
      m_Car = "拖拉机";
      m_Password = 123456;
    }
protected:
    string m_Car;
private:
    int m_Password; 
};

int* func();
int* func()
{
    //利用new关键字，可以将数据开辟到堆区
    int *p = new int(10);
    return p;
}

int main()
{
    //接收func函数的返回值
    int* p = func();
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}