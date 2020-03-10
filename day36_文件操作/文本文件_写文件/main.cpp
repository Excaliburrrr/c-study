# include <iostream>
# include <fstream>
using namespace std;


void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs << "天青色等烟雨，而我在等你" << endl;
    ofs << "炊烟袅袅升起，隔江千万里" << endl; 
    ofs.close();
}

int main()
{
    test01();
    return 0;
}