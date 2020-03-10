# include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal speak" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat speak" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Dog speak" << endl;
    }
};
/*
动态多态满足条件
1、有继承关系
2、子类重写父类的虚函数

动态多态的使用
父类的指针或者引用，接收子类对象
*/

void dospeak(Animal& animal)
{
    animal.speak();
}

int main()
{
    Cat cat;
    Dog dog;
    dospeak(cat);
    dospeak(dog);
    return 0;
}