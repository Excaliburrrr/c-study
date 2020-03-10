#include <iostream>

using namespace std;

// 数组元素的删除和插入

int main(){
    int power[] {1000, 1250, 1365, 2564, 4561};
    int powerLen = sizeof(power) / sizeof(int);
    int insertPower;
    int insertIndex;
    // 插入
    cout << "Please input number insert: ";
    cin >> insertPower;
    // 1. 找到第一个比插入数字大的位置insertIndex，
    for(int i = 0; i < powerLen; i++){
        if(insertPower <= power[i]){
             insertIndex = i;
             break;
        };    
    };
    // 2.从最后一个元素开始，将数字复制到后面一个元素中
    powerLen++;
    for(int i=powerLen - 1; i >= insertIndex; i--){
        power[i+1] = power[i];
    };
    power[insertIndex] = insertPower;

    for(int i=0; i < powerLen; i++){
        cout << power[i] << '\t' << endl;
    };
    return 0;
}