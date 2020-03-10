#include <iostream>
using namespace std;

int* func()
{
    //new返回的是该数据类型的指针
    int *p = new int(10);
    return p;
}



void show()
{
    int *p = func();
    cout << *p << endl;
    delete p;
    cout << *p << endl;
}
 
void test()
{
    int* arr = new int[10];
    for (int i=0; i<10; i++)
    {
        arr[i] = i + 100;
    }
     
    for(int i=0; i<10; i++)
    {
        cout << *(arr + i) << endl;
    }
    delete[] arr;

    for(int i=0; i<10; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    show();
    test();
    return 0;

}