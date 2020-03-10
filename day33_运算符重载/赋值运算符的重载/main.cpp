#include <iostream>
using namespace std;

class Data
{
public:
    int m_A;
    int* m_B;
    Data()
    {
        cout << "无参构造函数调用" << endl;
    };
    Data(int, int);
    // Data(const Data& d);
    Data& operator=(Data& d);
    ~Data();
};
Data::Data(int a, int b)
{
    m_A = a;
    m_B = new int(b);
};
// Data::Data(const Data& d)
// {
//     cout << "拷贝构造函数调用" << endl;
//     m_A = d.m_A;
//     m_B = new int(*d.m_B);
// };
Data::~Data()
{
    cout << "析构函数调用" << endl;
    if(m_B != NULL)
    {
        delete m_B;
        m_B = NULL;
    };
};

Data& Data::operator=(Data& a)
{
    // if (this->m_B != NULL)
    // {
    //     delete this->m_B;
    //     this->m_B = NULL;
    // };
    cout << "等号运算符重载！" << endl;
    this->m_A = a.m_A;
    this->m_B = new int(*a.m_B);
    return *this;
};

void test01()
{
    Data d(100, 125);
    Data d1(10, 100);
    Data d2;
    d = d2 = d1;
};

int main()
{
    test01();
    return 0;
}