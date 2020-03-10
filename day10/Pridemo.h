#ifndef PRIDEMO_H_INCLUDE
#define PRIDEMO_H_INCLUDE
#include <iostream>
using namespace std;


//函数定义
void input(int [], int);
void show(const int *, int);

//函数实现
void input(int values[], int len)
{
    string valueNames[] = {"strength", "intelligence", 
                "glamour", "morality", "temporament"};
    if(len > 5)
    {
        cout << "Array length exceeds bounds!" << endl;
        return; 
    };
    for(int i=0; i<len; i++)
    {
        cout << valueNames[i] << ": ";
        cin >> values[i];
    }
    return;  
}
void show(const int values[], int len)
{
    string valueNames[] = {"strength", "intelligence", 
                "glamour", "morality", "temporament"};
    for(int i=0; i<len; i++)
    {
        cout << valueNames[i] << ": " << values[i] << endl;
    };
    return;
}

//使用指针作为参数传递
void show1(const int *values, int len)
{
    string valueNames[] = {"strength", "intelligence", 
                "glamour", "morality", "temporament"};
    for(int i=0; i<len; i++)
    {
        cout << valueNames[i] << ": " << *(values+i) << endl;
    };
    return;

}
#endif 