#include <iostream>
#include "Pridemo.h"


using namespace std;

/*
按值传递：
    ×  给函数传递变元（参数）时，变元（参数）值不会直接传递给函数，而是
       先制作变元（参数）值的副本，储存在栈上，再使这个副本可用于函数，而不是使用初值。
*/

/*
注意：
1、数组作为函数实参时，只传递数组的地址（首地址），并不传递整个数组空间
2、当用数组名作为实参调用函数时。数组的首地址指针就被传递到函数中
*/

int main()
{
    int values[5];
    input(values, sizeof(values)/sizeof(int));
    show(values, 5);
    cout << endl;
    show1(values, 5);
}