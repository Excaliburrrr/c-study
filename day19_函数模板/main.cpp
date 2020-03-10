#include <iostream>
using namespace std;

/*
所谓函数模板，实际上就是建立一个通用函数
    函数定义时不指定具体的数据列席（使用虚拟类型代替）
    函数被调用时编译器根据实参反推数据类型-类型的参数化
*/

/*
//模板头与函数声明/定义永远是不看分割的整体！
template <typename 类型参数1, typename 类型参数2, ...>
返回值类型 函数名(形参列表){
    //在函数体中可以使用类型参数
}
*/
template <typename T>
void Swap(T&, T&);

 template<typename T>
 void Swap(T& a, T& b)
 {
     T temp = a;
     a = b;
     b = temp;
 }

 int main()
 {
    int a = 10, b = 100;
    double c = 12.5, d = 112.3;
    char e = 'a', f = 'd';
    Swap(a, b);
    cout << "a: " << a << '\t' << "b: " << b << endl;

    Swap(c, d);
    cout << "c: " << c << '\t' << "d: " << d << endl;

    Swap(e, f);
    cout << "e: " << e << '\t' << "f: " << f << endl;
 }