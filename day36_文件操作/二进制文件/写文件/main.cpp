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
   //1、包含头文件
   //2、创建流对象
   ofstream ofs;

   //3、打开文件
   ofs.open("Data.txt", ios::out | ios::binary);

   //4、写文件
   Data d = {18, 1235};
   ofs.write((const char *)&d, sizeof(Data));

   //5、关闭文件
   ofs.close();
}

int main()
{
    test01();
    return 0;
}