# pragma once
# include <iostream>
# include <string>
using namespace std;

template <class T>
class BoudingBox
{
public:
    T x_min;
    T y_min;
    T x_max;
    T y_max;
    string obj_name;
    BoudingBox(T xMin, T yMin, T xMax, T yMax, string objName);
    void showBBox();
};

template <class T>
BoudingBox<T>::BoudingBox(T xMin, T yMin, T xMax, T yMax, string objName)
{
    this->x_min = xMin;
    this->x_max = xMax;
    this->y_min = yMin;
    this->y_max = yMax;
    this->obj_name = objName;
}

template <class T>
void BoudingBox<T>::showBBox()
{
    cout << "object name: " << this->obj_name << endl;
    cout << "x_min : " << this->x_min << "  " << "y_min : " << this->y_min << endl;
    cout << "x_max : " << this->x_max << "  " << "y_max : " << this->y_max << endl;
}
