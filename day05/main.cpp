#include <iostream>
#include <vector>
#include <cstdlib>
#include <array>

using namespace std;

int main()
{
    //指针
    /*
    1、int* p的写法偏向于地址，即p就是一个地址变量，表示一个十六进制地址；
    2、int *p的写法偏向于值，*p是一个整型变量，能够表示一个整型值；
    3、声明中的*号和使用中的*号含义完全不同；
    */
    /*
    double num = 1024.5;
    char ch = 'a';
    char* ptr_ch = &ch; // char型指针在c/c++中默认为字符串！！, 如果需要打印出地址需要用(void *)强转类型
    cout << (void *)ptr_ch << '\t' << *ptr_ch << endl;
    double* ptr_num = &num; // 指针类型必须与原变量类型一致  
    cout << ptr_num << endl;
    cout << *ptr_num << endl; //间接运算符，根据地址找到值 num=10
                              //通过地址访问变量
    */

    //空指针
    /*
    double* ptr_num = nullptr; //如果不给初值，会出现野指针的情况
    cout << ptr_num << endl; // 0
    //需要包含cstdlib
    int* ptr3 = NULL; //等价于 int* ptr3 = 0;
    cout << ptr3 << endl;
    */

    // void* 指针
    /*
    注意：
    1、void* 指针存放一个内存地址，地址指向的内容是什么类型不能确定；
    2、void* 类型指针一般用来；拿来和别的指针比较，作为函数的输入和输出；赋值给另一个
       void* 指针。
    */
    double num = 1024.5;
    double* ptr1 = &num;
    void* ptr2 = &num; //可以只想任意类型
    cout << boolalpha;
    cout << (ptr1 == ptr2) << endl;

    return 0;

};