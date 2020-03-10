#include <iostream>
using namespace std;


//函数模板

//交换两个数(整型、浮点型...)
template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}


template<typename T>
void mysort(T arr[], int len)
{
    for (int i = 0;i<len;i++)
    {
        int max = i;
        for (int j = i;j<len;j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            Swap<T>(arr[i], arr[max]);
        }
    }
}

int main()
{
    double a = 3.14, b = 2.56;
    Swap(a, b); //自动类型推导
    //显示指定类型
    //Swap<double>(a, b)
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // int arr[] = {1, 5, 9, 2, 10};
    // int len = sizeof(arr)/sizeof(int);

    char charArr[] = "acdebf";
    int len = sizeof(charArr) / sizeof(char);
    
    mysort<char>(charArr, len);
    for (int i = 0;i<len;i++)
    {
        cout << charArr[i] << " ";
    }
    cout << endl;
    return 0;
}