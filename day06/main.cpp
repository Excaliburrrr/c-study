#include <iostream>

using namespace std;

int main()
{
    //引用(reference)
    /*
    注意：
    1、引用并非对象，只是为一个已经存在的对象起的别名；
    2、引用只能绑定在对象上，不能与字面值或者某个表达式的计算
       结果绑定在一起；
    3、引用必须初始化，所以使用引用之前不需要测试其有效性，因此使用引用
       可能回避使用指针效率高 
    */
    //为对象起了另外一个名字(引用即别名)
    int int_value = 1024;
    // refValue指向int_value, 是int_value的另一个名字
    // 引用的同时必须被初始化
    int& refValue = int_value;
    cout << boolalpha;
    cout << (refValue == int_value) << endl;
    //常量引用
    const double& refNum = 100;
    cout << refNum << endl; 
    return 0;
    /*
    指针和引用
    1、引用是对指针进行了简单的封装，底层仍然是指针；
    2、获取引用地址时，编译器会进行内部转换。
    */


}