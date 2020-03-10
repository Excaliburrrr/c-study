#include <iostream>
using namespace std;

/*
内联(inline)函数
是c++为提高程序运行速度所做出的一项改进
与常规函数的区别不在于编写方式  

使用建议：
如果执行函数代码的时间比处理函数调用机制的时间长，
则节省的时间将只占整个过程的一小部分
如果代码执行的时间很短，内联调用就可以节省大部分时间。

使用内联特性(采取其一)
1、在函数声明前加关键字inline
2、在函数定以前加关键字inline
*/

void swap1(int, int);
void swap2(int*, int*);
void swap3(int&, int&);

void swap1(int num1, int num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

void swap2(int* p1, int* p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void swap3(int& num1, int& num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int main()
{
    int num1 = 5, num2 = 10;
    swap1(num1, num2);
    cout << "After swap1: " << num1 << "\t" << num2 << endl;
    swap2(&num1, &num2);
    cout << "After swap2: " << num1 << "\t" << num2 << endl;
    swap3(num1, num2);
    cout << "After swap3: " << num1 << "\t" << num2 << endl;
}