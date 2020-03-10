#include <iostream>
#include <cstdlib>
#include <array>
#include <algorithm>
using namespace std;

int main(){
    // 向量容器的定义
    /*
    vector<double> vec1;
    vector<string> vec2(5);
    vector<int> vec3(20, 998);
    // 添加元素
    vec3.push_back(100);
    for(int i = 0; i < vec3.size(); i++){
        cout << vec3[i] << endl;
    };
    // 集合的通用方法，使用迭代器 iterator
    // 一下是迭代器的基本使用方法
    vector<int>::iterator it; //得到迭代对象, 实际上是一个指针对象
    // it.begin
    for(it = vec3.begin(); it != vec3.end(); it++){
        cout << *it <<endl;
    }
    //排序
    // 在algorithm中定义了sort方法
    sort(vec3.begin(), vec3.end()); //从小到大
    //reverse(vec3.begin(), vec3.end()); // 逆序
    for(it = vec3.begin(); it != vec3.end(); it++){
        cout << *it <<endl;
    }
    */
    array<double, 5> nums {2513.2, 1813.15, 5315.213, 5345.52, 1513.21};

    nums.at(2) = 100;
    cout << nums.at(2) << endl;    // 使用at时，索引越界会报错！！




    return 0;
}