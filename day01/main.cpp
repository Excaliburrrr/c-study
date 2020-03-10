#include <iostream>

using namespace std;

int main(){
/**
    int num[] = {198, 98, 'c', 230}; // 由于字符在c++/c中是采用整型来表示
    bool Bool[] = {1, 0, true, false, 38, -1};
    cout << num[2] << endl;
    cout << Bool[4] << endl;
**/
/**
   int N = 100;
   char num[N];
   num[0] = 'a';
   cout << sizeof(num) << endl;
   cout << num[0] << endl;
   cout << num[1] << endl;
**/
// 初始化数组
/*
    int array[] = {1}; // 等于号可以省略
    array[0] = 12;
    array[1] = 13;
    cout << sizeof(array) << endl;
    cout << array[0] << endl;
*/
//动态的从键盘录入信息，并赋值
/*
    const int N = 5;
    int nums[N];
    for(int i=0; i<sizeof(nums) / sizeof(int); i++){
        cout << "Please input #" << (i+1) << " element: ";
        cin >> nums[i];
    };
    int sum = 0;
    for(int i=0; i<N; i++){
        sum += nums[i]; 
        cout << nums[i] << endl;
    };
    int mean = sum / (sizeof(nums) / sizeof(int));
    cout << "The sum of this array is: " << sum << endl;
    cout << "The mean value of this array is: " << mean << endl; 
    return 0;
*/
// 求数组的最大值和最小值
    int nums[] {8, 12, 6, 3, 25, 198};
    int numsLen = sizeof(nums) / sizeof(int);
    int max = nums[0];
    int maxIndex;
    for(int i=0; i<numsLen; i++){
        if(max <= nums[i]){
            max = nums[i];
            maxIndex = i;
        }
    };
    cout << "max value in this array is: " << max << endl;
    cout << "index of max value in this array is: " << maxIndex << endl;

}