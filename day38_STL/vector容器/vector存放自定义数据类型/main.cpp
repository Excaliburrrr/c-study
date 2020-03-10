# include <iostream>
# include <vector>
# include "./source/bbox.hpp"
using namespace std;


void test01()
{
    BoudingBox<double> bbox1(112.33, 456.22, 1564.51, 521.564, "perdestrain");
    BoudingBox<double> bbox2(115.33, 121.122, 1564.51, 521.564, "perdestrain");
    BoudingBox<double> bbox3(542.33, 253.212, 1564.51, 521.564, "perdestrain");
    BoudingBox<double> bbox4(877.33, 584.12, 1564.51, 521.564, "perdestrain");

    vector< BoudingBox<double>* > vb;
    vb.push_back(&bbox1); // push back : 尾插
    vb.push_back(&bbox2);
    vb.push_back(&bbox3);
    vb.push_back(&bbox4);

    for(vector< BoudingBox<double>* >::iterator it=vb.begin(); it!=vb.end(); it++)
    {
        (*it)->showBBox();
        cout << endl;
    } 
}

int main()
{
    test01();
    return 0;
}
