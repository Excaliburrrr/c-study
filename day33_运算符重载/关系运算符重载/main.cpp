# include <iostream>
using namespace std;

class Data
{
public:
    Data(int, int);
    bool operator==(Data& d);
    int m_A, m_B;
};

Data::Data(int a, int b)
{
    m_A = a;
    m_B = b;
}

bool Data::operator==(Data& d)
{
    cout << "调用关系运算符重载函数" << endl;
    if((d.m_A == this->m_A)&&(d.m_B == this->m_B))
    {
        return true;
    }
    return false;
}

string isequal(Data& d1, Data& d2)
{
    string result;
    if (d1 == d2)
    {
        result = "True";
    }
    else
    {
        result = "False";
    }
    return result;
}

void test01()
{
    Data d1(10, 100);
    Data d2(10, 100);
    Data d3(5, 100);
    cout << isequal(d1, d2) << endl;
    cout << isequal(d1, d3) << endl;
}

int main()
{
    test01();
    return 0;
}