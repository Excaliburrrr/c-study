#include <iostream>
using namespace std;
/*
注意：
1、函数原型与函数定义的头部类似，最后以分号结尾；
2、函数原型中的参数名称可以省略，这些参数类型；
3、c++中返回的类型不能是数组，但可以是其他任何类型（可以将
  数组作为结构体或对象组成部分返回）
*/
int sum(int, int); //函数原型

int main()
{
    int result = sum(5, 6);
    cout << result << endl;

    return 0;
}

int sum(int num1, int num2)
{
    int result = num1 + num2;
    return result;
}