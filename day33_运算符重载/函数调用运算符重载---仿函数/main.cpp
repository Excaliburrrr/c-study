#include <iostream>
using namespace std;

class MyPrint{
public:
    void operator()(string test)
    {
        cout << test << endl;
    }
};

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1+num2;
    }
};

void test01()
{
    MyPrint myprint;
    myprint("hello world");
    cout << MyAdd()(15, 16) << endl; //类型名+小括号=匿名对象，调用后立即释放
}

int main()
{
    test01();
    return 0;
}