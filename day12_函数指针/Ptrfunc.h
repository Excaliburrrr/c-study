#ifndef PTRFUNC_H_INCLUDE
#define PTRFUNC_H_INCLUDE
#include <iostream>
using namespace std;

/*
函数的地址是存储其机器语言代码的内存开始地址
好处：可以在不同的时间使用不同的函数
*/
// 函数指针的声明
int pow(int, int); // 函数原型
int (*ptrPow)(int, int); 
/*
注意：
1、该语句声明了一个指针ptrSum，指向一个函数
2、double *ptrSum(double, double)不是函数指针，而是：
   声明了一个函数ptrSum，返回 double* 类型
*/
int pow(int num1, int num2)
{
    int result = 1;
    for(int i=0; i<num2; i++)
    {
        result *= num1;
    }
    return result;
}

#endif