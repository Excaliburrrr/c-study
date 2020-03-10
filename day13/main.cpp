#include <iostream>
#include "Mycalc.hpp"
using namespace std;
/*
需求说明：
使用函数指针实现加减乘除运算：
    double addition(double, double)
    double substraction(double, double)
    double multiplication(double, double)
    double division(double, double)
    double (*ptrCalc)(double, double)
*/
int main()
{
    //double (*ptrCalc)(double, double);
    //使用auto可以无视类型：
    /*
    typedef double (*ptrCalc)(double, double);
    ptrCalc ptrCalc1;
    */
    auto ptrCalc = addition;
    double num1, num2;
    double result;
    char opt;
    cout << "Please input two numbers: ";
    cin >> num1 >> num2;
    cout << "Please input operator: ";
    cin >> opt;
    switch(opt)
    {
    case '+':
        //调用加法函数
        ptrCalc = addition;
        break;
    case '-':
        //调用减法函数
        ptrCalc = subtraction;
        break;
    case '*':
        //调用乘法函数
        ptrCalc = multiplication;
        break;
    case '/':
        //调用除法函数
        ptrCalc = division;
        break;
    default:
        cout << "Invalid operator!" << endl;
        return 0;
    };
    print_result(ptrCalc, num1, num2);
    return 0;
}