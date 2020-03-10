
#pragma once
#include <iostream>

template<class T1, class T2>
class BoudingBox
{
public:
    T1 x_min;
    T1 y_min;
    T1 x_max;
    T1 y_max;
    T2 obj_name;
    void BoudingBox(T1 xMin, T1 yMin, T1 xMax, T1 yMax, T2 objName);
    void showBox();
};