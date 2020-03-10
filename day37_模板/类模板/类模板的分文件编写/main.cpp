# include <iostream>
//第一种解决方法：直接包含源文件
//# include "./源文件/bbox.cpp"
//第二种方法：将.h和.cpp的内容写在一起，并将后缀名改为.hpp
# include "bbox.hpp"
# include <string>
using namespace std;

void test01()
{
    BoudingBox<int, string> bbox(45, 123, 22, 166, "Perdestrian");
    bbox.showBox();
}


int main()
{
    test01();
    return 0;
}






