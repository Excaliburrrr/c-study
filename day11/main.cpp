#include <iostream>
#include "TDdemo.h"
using namespace std;

//二维数组作为函数的参数
int main(){
    double arr[4][5]={{1, 2, 3, 4, 5}, 
                      {4, 5, 6, 7, 8},
                      {7, 8, 9, 10, 11},
                      {10, 11, 12, 13, 14}};
    show(arr, 4);          
}