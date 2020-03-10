#ifndef PART_H_INCLUDE
#define PART_H_INCLUDE

int& sum();
int& sum2();
void test();

int& sum()
{
    int num = 10; //局部变量存放在四区中的栈区
    int& refNum = num;
    return refNum;
}

int& sum2()
{
    static int num = 10; //静态变量，存放在全局区，全局区上的数据在程序结束后释放
    return num;
}

void test()
{
    /*
    int x = 100;
    int y = 50;
    int z = 1024;
    int v = 16515;
    int w = 165132;
    */
    int &ref = sum2();
    sum2() = 1000;
    cout << "ref = "<< ref << endl;
}

#endif