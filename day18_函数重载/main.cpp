#include <iostream>
using namespace std;

/**
 * 函数重载（overloading）
    * 指可以有多个同名的函数
    * 函数名相同，参数列表不同（特征不同） 
 * 注意：
    * 从编译器的角度看，eating(string)和eating(string&)的特征标
      是相同的，调用时都可以写作：eating(food)；为避免混乱，编译器
      把类型引用和类型本身视为同一个特征标。
**/
 