#ifndef MYCALC_H_INCLUDE
#define MYCALC_HINCLUDE
#include <iostream>
using namespace std;
//自定义计算器，使用指针函数

double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
/* 打印计算结果 */
//使用函数指针
void print_result(double (*)(double, double), double, double);

void print_result(double (*ptrCalc)(double, double), double num1, double num2)
{
    double result = ptrCalc(num1, num2);
    cout << "Operation result: " << result << endl;
}

double addition(double num1, double num2)
{
    return num1 + num2;
}

double subtraction(double num1, double num2)
{
    return num1 - num2;
}

double multiplication(double num1, double num2)
{
    return num1 * num2;
}

double division(double num1, double num2)
{
    if(num2 == 0){
        cout << "Invalid input!" << endl;
        return 0;
    }
    return num1 / num2;
}

#endif