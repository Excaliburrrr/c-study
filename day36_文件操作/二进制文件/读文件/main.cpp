#include <iostream>
#include <fstream>
using namespace std;


class Data
{
public:
    int m_Num1;
    int m_Num2;
};

void test01()
{
    ifstream ifs;

    ifs.open("Data.txt", ios::in|ios::binary);

    if(!ifs.is_open())
    {
        cout << "读取文件失败" << endl;
        return;
    }

    Data d;

    ifs.read((char *)&d, sizeof(Data));

    cout << d.m_Num1 << endl;
    cout << d.m_Num2 << endl;

    ifs.close();

}

int main()
{
    test01();
    return 0;
}
