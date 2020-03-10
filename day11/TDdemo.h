#ifndef TDDEMO_H_INCLUDE
#define TDDEMO_H_INCLUDE
//二维数组的传参
#include <iostream>
using namespace std;
void show(double (*)[5], int);

void show(double (*arr)[5], int len)
{
    for(int i=0; i<5; i++){
        for(int j=0; j<len; j++){
            cout << *(*(arr+i)+j) << '\t';
        };
        cout << endl;
    }
}
#endif