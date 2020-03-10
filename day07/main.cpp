#include <iostream>
using namespace std;

int main()
{
    //指针与数组
    /* 
    double score[] {11, 22, 33, 44, 55};
    double * ptr_score  = score;
    cout << sizeof(score) << '\t' << sizeof(ptr_score) << endl;
    */
    //指针的运算
    //1、指针的算数运算
    /*
    int i;
    double score[5] {98, 87, 65, 43, 76};
    double* ptr_score;
    ptr_score = score;
    for(i=0; i<5; i++){
        cout << *ptr_score++ << endl;
    }
    for(i=0; i<5; i++){
        cout << *(score+i)<< endl;
    }
    */
    // 使用指针实现数组的逆序
    /*
    int arrays[] {35, 39, 43, 48, 56, 75};
    int *ptr = arrays;
    int *ptr_start = arrays;
    int *ptr_end = arrays + 5;
    int temp;
    while(ptr_start <= ptr_end)
    {
        temp = *ptr_start;
        *ptr_start = *ptr_end;
        *ptr_end = temp;
        ptr_start++;
        ptr_end--;
    }
    for(int i=0; i<6; i++)
    {
        cout << *(arrays + i) << endl;
    };
    */
    //使用指针创建二位数组
    int (*p)[3] = new int[5][3];
    p[3][2] = 998;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
        {
           // cout << p[i][j] << ",";
           cout << *(*(p+i)+j) << ",";
        };
        cout << endl;
    };


    return 0;
}