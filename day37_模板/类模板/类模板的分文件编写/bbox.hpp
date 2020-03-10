#pragma once
#include <iostream>
using namespace std;

template<class T1, class T2>
class BoudingBox
{
public:
    T1 x_min;
    T1 y_min;
    T1 x_max;
    T1 y_max;
    T2 obj_name;
    BoudingBox(T1 xMin, T1 yMin, T1 xMax, T1 yMax, T2 objName);
    void showBox();
};

template<class T1, class T2>
BoudingBox<T1, T2>::BoudingBox(T1 xMin, T1 yMin, T1 xMax, T1 yMax, T2 objName)
{
    this->x_min = xMin;
    this->y_min = yMin;
    this->x_max = xMax;
    this->y_max = yMax;
    this->obj_name = objName;
}

template<class T1, class T2>
void BoudingBox<T1, T2>::showBox()
{
    cout << "BoudingBox : " << this->obj_name << endl;
    cout << "x_min : " << this->x_min << "  " << "y_min : " << this->y_min << endl;
    cout << "x_max : " << this->x_max << "  " << "y_max : " << this->y_max << endl;
}