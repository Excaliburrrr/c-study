#include <iostream>
using namespace std;

int main()
{
    int const a = 100;
    cout << a << endl;
    int const *ptr_a = &a;
    cout << ptr_a << endl;
    int b = 200;
    ptr_a = &b;
    cout << ptr_a << endl;
}