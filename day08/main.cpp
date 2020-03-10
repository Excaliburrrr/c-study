#include <iostream>
using namespace std;

int main()
{
    //1、在运行阶段为一个int值分配未命名的内存
    //2、使用指针来访问(指向)这个值（右->左）
    int* ptr_int = new int;
    //释放由new分配的内存 
    delete ptr_int;
     
    // 动态分配的数组
    int* intArray = new int[10];
    for(int i=0; i<10; i++)
    {
        cout << "please input #" << i << " element: ";
        cin >> *(intArray+i);
        cout << endl;
    }
    for(int i=0; i<10; i++)
    {
        cout << *(intArray+i) << endl; 
    }
    delete [] intArray;
    /*
    注意：
    1、不要用delete释放不是new分配的内存;
    2、不要用delete释放统一内存两次;
    3、如果使用new[]为数组分配内存，则对应delete[]释放内存;
    */
};