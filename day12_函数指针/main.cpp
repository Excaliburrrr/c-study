#include <iostream>
#include "Ptrfunc.h"

using namespace std;


int main()
{   
    //int pow(int, int);
    //声明函数指针
    int (*ptrPow)(int, int);
    //让声明的函数指针指向函数，以便调用
    ptrPow = pow;
    int num=5;
    cout << ptrPow(num, 3) << endl;
}