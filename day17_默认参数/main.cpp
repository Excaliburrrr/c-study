#include <iostream>
using namespace std;

/**
注意：
1、默认值可以在函数原型或定义中给出，不能在这两个位置同时出现
2、对于带参数列表的函数，必须从右向左添加默认值
    void test1(int a, int b = 5, int c = 10); //正确
    void test2(int a, int b = 5, int c); //错误
**/

void sample(int = 10);

void sample(int num)
{
    cout << num << endl;
}


int main(){
    sample();
}