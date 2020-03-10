# include <iostream>
using namespace std;

class BaseClass
{
public:
    BaseClass()
    {
        cout << "父类中的构造函数" << endl;
    }
    ~BaseClass()
    {
        cout << "父类中的析构函数" << endl;
    }
};

class SonClass : public BaseClass
{
public:
    SonClass()
    {
        cout << "子类中的构造函数" << endl;
    }
    ~SonClass()
    {
        cout << "子类中的析构函数" << endl;
    }

};


int main()
{
    SonClass s;
    return 0;
}