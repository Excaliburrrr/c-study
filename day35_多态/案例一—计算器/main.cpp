#include <iostream>
#include <string>
using namespace std;


class AbstractCalculator
{
public:
    int m_Num1;
    int m_Num2;
    virtual int getResult() = 0; //纯虚函数
};

class AddCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 + m_Num2;
    }
};


class MulCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 * m_Num2;
    }
};


class SubCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 - m_Num2;
    }
};


void test01()
{
    AbstractCalculator* abs;

    abs = new AddCalculator;
    abs->m_Num1 = 10;
    abs->m_Num2 = 20;
    cout << abs->m_Num1 << " + " << abs->m_Num2 << " = " << abs->getResult() << endl;
    delete abs;

    abs = new MulCalculator;
    cout << abs->m_Num1 << " * " << abs->m_Num2 << " = " << abs->getResult() << endl;
    delete abs;

    abs = new SubCalculator;
    cout << abs->m_Num1 << " - " << abs->m_Num2 << " = " << abs->getResult() << endl; 
    
}

int main()
{
    test01();
    return 0;
}