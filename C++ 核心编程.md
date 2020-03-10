# C++ 核心编程

## 1 内存分区模型

C++程序在执行时，将内存大方向划分为__4个区域__

* 代码区：存放函数体的二进制代码，由操作系统进行管理的
* 全局区：存放全局变量和静态变量以及常量
* 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
* 堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收



__内存四区意义__：

不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程 

### 1.1 程序运行前

在程序编译后，生成了exe可执行程序，__未执行该程序前__分为两个区域

__代码区__：

存放CPU执行的机器指令

* 代码区是__共享__的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
* 代码区是__只读__的，使其只读的原因是防止程序意外地修改了它的指令

__全局区__：

全局变量（_写在 main() 函数体外的变量_）和静态变量（_在普通变量前加关键字 static_）存放在此

* 全局区还包含了常量区 ，字符串常量和其他常量也存放在此
* 该区域的数据在程序结束后由操作系统释放



### 1.2 程序运行后

__栈区__：

* 由编译器自动分配释放，存放函数的参数值，局部变量等
* 注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放



示例：

````c++
int * func()
{
    int  a = 10;
    return &a;
}
int main()
{
    int *p = func();
    
    cout << *p << endl;
    
}
````

__堆区__ ：

* 由程序员分配释放，若程序员不释放，程序结束时由操作系统回收
* 在C++中主要利用new在堆区开辟内存

__示例__：

````c++
int *func()
{
    int* a = new int(10);
    return &a;
}

int main()
{
    int* p = func();
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}
````

__总结__：

堆区数据由程序员管理开辟和释放

堆区数据利用new关键字进行开辟内存



### 1.3 new操作符

C++中利用 `new` 操作符在堆区开辟数据

堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 `delete`

语法： `new 数据类型`

利用new创建的数据，__会返回数据对应类型的指针__

示例1：基本语法

````c++
int * func()
{
    //new 一个整型变量
    int* a = new int(10);
    return a;
}


int main()
{
    int *p = func();
    cout << *p << endl;
    // new 一个整型数组，内有10个元素
    int* arr = new int[10];
}

````

 

## 2 引用

### 2.1 引用的基本使用

__作用__：给变量起别名

__语法__：数据类型　&别名 = 原名

__注意__：

* 引用必须初始化
* 引用在初始化后，不可以改变

__示例__：

````c++
int main()
{
    int a = 10;
    int &b = a;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
````



### 2.2 引用做函数参数

__作用__：函数传参时，可以利用引用技术让形参修饰实参

__优点__：可以简化指针修改实参



__示例__：

````c++
//1.值传递
void mySwap1(int a, int b)
{
    temp = a;
    a = b;
    b = temp;
}

void mySwap2(int* a, int* b)
{
    temp = *a;
    *a = *b;
    *b = temp;
}

void mySwap3(int& a, int& b)
{
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10, b = 20;
    cout << "a = " << a << '\t' << "b = " << b << endl;
    mySwap1(a, b);
    cout << "a = " << a << '\t' << "b = " << b << endl;
    mySwap2(&a, &b);
    cout << "a = " << a << '\t' << "b = " << b << endl;
    mySwap3(a, b);
    cout << "a = " << a << '\t' << "b = " << b << endl;
    return 0;
}
````

> 总结：通过引用参数产生的效果同按地址传递是一样的，引用的语法更清楚简单



### 2.3 引用作为函数返回值

__作用__：引用是可以作为函数的返回值存在的

注意：__不要返回局部变量的引用__

用法：函数调用作为左值



### 2.4 引用的本质

本质：__引用的本质在c++内部实现是一个指针常量__

讲解示例：

````c++
//发现使用引用，转换为　int* const ref = &a;
void func(int& ref)
{
    ref = 100;
}
int main()
{
    int a = 10;
    //自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
    int& ref = a;
    ref = 20; //内部发现ref是引用，自动帮我们转换为：*ref = 20;
    
    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;
    func(a);
    return 0;
}
````



### 2.5 常量引用

__作用__：常量引用主要用来修饰形参，防止误操作

在函数形参列表中，可以加const修饰形参，防止形参改变实参

__示例__ ：

````C++
//引用使用的场景，通常用来修饰形参
void showValue(const int& v)
{
    cout << v << endl;
}
int main()
{
    int v = 10;
    showValue(v);
}
````



## 3 函数高级

### 3.1 函数占位参数

C++中函数的形参类别里可以有占位参数，用来占位，调用函数时必须填补该位置

__语法__：`返回值类型　函数名(数据类型){}`

__示例__：

````c++
//函数占位参数，占位参数也可以有默认值
void func(int a, int)
{
    cout << "this is func" << endl;
}
int main()
{
    func(10, 10); //占位参数必须填补
    　
}
````



### 3.2 函数重载

#### 3.2.1 函数重载概述



__作用__：函数名可以相同，提高复用性



__函数重载满足条件__：

* 同一个作用域下
* 函数名相同
* 函数参数__类型不同__或者__个数不同__或者__顺序不同__



__注意__：函数的返回值不可以作为函数重载的条件　



### 3.2.2 函数重载的注意事项

* 引用作为重载条件
* 函数重载碰到函数默认参数

__示例__：

````c++
//函数重载注意事项
//1、引用作为重载条件
void func(int &a)
{
    cout << "func (int &a) 调用" << endl;
}

void func(const int &a)
{
    cout << "func (const int &a) 调用" << endl; 
}

int main()
{
    int a = 10;
    func(a); //调用func(int &a)
    func(10); //调用func(const int &a)
}
````

````c++
//2、函数重载碰到默认参数
void func(int a)
{
    cout << "func(int a)的调用" << endl;
}
void func1(int a, int b=10)
{
    cout << "func(int a, int b)" << endl;
}
int main()
{
    func(10); //出错！当函数重载碰到默认参数，出现二义性，尽量避免这种情况
}
````



## 4 类和对象

C++ 面向对象的三大特性：__封装__，__继承__，__多态__ 

C++任务万事万物皆对象，对象上有其属性和行为



### 4.1 封装

#### 4.1.1 封装的意义

封装是C++面向对象的三大特性之一

封装的意义：

* 将属性和行为作为一个整体，表现生活中的事物
* 降属性和行为加以权限控制

__封装的意义一__：

​	在设计类的时候，属性和行为写在一起，表现事物

__语法__：`class 类名{	访问权限: 属性/行为}；`

__示例1__：设计一个圆类，求圆的周长

````c++
double const PI = 3.14;

class Circle
{
public:
    double m_r;
    double get_grith()
    {
        double m_grith = 2 * PI * m_r;
        return m_grith;
    };
};

int main()
{
    Circle c1;
    double grith;
    c1.m_r = 5;
    grith = c1.get_grith ();
    cout << "grith of c1: " << grith << endl;
}
````

__封装的意义二__：

类在设计时，可以把属性和行为放在不同的权限下，加以控制

访问权限有三种：

1、public		  公共权限

2、protected	保护权限

3、private		 私有权限

__示例__ :

````c++
class Person
{
public:
    string m_Name;
 	int ID;
protected:
    string m_Car;
private:
    int m_Password;
}
````



#### 4.1.2 struct和class区别

在C++中struct和class唯一的区别在于默认的访问权限不同

区别：

* struct 默认权限为公共
* class  默认权限为私有

#### 4.1.3 成员属性设为私有

__优点1__：将所有成员属性设置为私有，可以自己控制读写权限

__优点2__：对于写权限，我们可以检测数据的有效性



### 4.2 对象的初始化和清理

* 生活中我们买的电子产品都基本会有出厂设置，在某一天我们不用的时候也会删除一些自己的信息数据保证安全
* C++中的面向对象来源于生活，每个对象也都会有初始设置以及对象销毁前的清理数据的设置



### 4.2.1构造函数和析构函数

对象的__初始化和清理__也是两个非常重要的安全问题

​		一个对象或者变量没有初始状态，对其使用后果是未知的

​		同样的使用完了一个对象或变量，没有及时清理，也会造成一定的安全问题



c++利用了__构造函数__和__析构函数__解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作。

独享的初始化和清理工作是编译器强制要我们做的事情，因此如果我们不提供__构造和析构函数，编译器会提供编__

__译器提供的构造函数和析构函数是空实现__。

* 构造函数：主要作用在创建对象时为对象的成员属性赋值，构造函数有编译器自动调用，无须手动调用。
* 析构函数：主要作用在于对象销毁前系统自动调用，执行一些清理工作。



__构造函数语法__：`类名(){}`

​	1、构造函数，没有返回值也不谢void

​	2、函数名称与类名相同

​	3、构造函数可以有参数，因此可以发生重载

​	4、程序在调用对象时候会自动调用构造，无须手动调用，而且只会调用一次



__析构函数语法__：`~类名(){}`

​	1、析构函数，没有返回值也不写void

​	2、函数名称与类名相同，在名称前加上符号 ~

​	3、析构函数不可以有参数，因此不可以发生重载

​	4、程序在对象小回迁会自动调用析构，无须手动调用，而且只会调用一次



#### 4.2.2 构造函数的分类及调用

两种分类方式：

​		按参数分为：有参构造和无参构造

​		按类型分为：普通构造和拷贝构造

三种调用方式：
		括号法

​		显示法

​		隐式转换法

__示例__：

````c++
#include <iostream>
using namespace std;

class Person
{
public:
    int m_age;
    //普通构造函数
    //默认(无参)构造函数
    //有参构造函数　
    Person(int age)
    {
        m_age = age;
        cout << "age = " << age << endl;
        cout << "Person的构造函数" << endl;
    };
    ~Person()
    {
        cout << "Person的析构函数" << endl;
    };
};

class People
{
public:
    int m_age;
    People (const Person &p){
       m_age = p.m_age;
    } //拷贝构造，形参列表中带const关键字
};

int main(){
    Person p1(22);
    People p2(23);
    return 0;
}
````

__注意事项__：

​		1、调用默认构造函数的时候不要叫括号，因为编译器会认为是一个函数声明，不会认为在创建对象。

​		2、不要利用拷贝构造函数初始化匿名对象，会出现__重定义__的错误



#### 4.2.3 拷贝构造函数调用机制

C++中拷贝构造函数调用时机通常有三种情况

* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象



#### 4.2.4 构造函数调用规则

默认情况下，C++编译器至少给一个类添加3个函数

1、默认构造函数（无参，函数体为空）

2、默认析构函数（无参，函数体为空）

3、默认拷贝构造函数，对属性进行值拷贝（默认提供的拷贝构造函数会对所有的属性进行一个简	  单的值拷贝操作）



构造函数调用规则如下：

* 如果用户定义有参构造函数，C++编译器不会再提供默认__无参构造函数__，但是会提供默认__拷贝构造__
* 如果用户定义拷贝构造函数，C++编译器不会再提供其他构造函数

__示例__:

````c++
class Person
{
public:
    int m_Age;
    //无参（默认）构造函数
    Person()
    {
        cout << "无参构造函数" << endl;
    }
    Person(int a)
    {
        cout << "有参构造函数" << endl;
        m_Age = a;
    }
    Person(const Person& p)
    {
        cout << "拷贝构造函数" << endl;
        m_Age = p.m_Age;
    }
    ~Person()
    {
        cout << "析构函数" << endl;
    }
}
````



#### 4.2.5 深拷贝与浅拷贝

__浅拷贝__：简单的赋值拷贝操作，编译器提供的 `=` 操作

__深拷贝__：在堆区重新申请空间，进行拷贝操作

__示例__：

````c++
#include <iostream>
using namespace std;

class Person
{
public:
    int m_Age;
    int *m_Height;
    //无参（默认）构造函数
    Person()
    {
        cout << "无参构造函数！" << endl;
    };
    //有参构造函数
    Person(int age, int height)
    {
        cout << "有参构造函数!" << endl;
        m_Height = new int(height); // 用new将m_Height创建在堆区
        cout << m_Height << endl;
        m_Age = age;
    }; 
    Person(const Person &p)
    {
        cout << "拷贝构造函数!" << endl;
        m_Age = p.m_Age;
        //深拷贝，重新在堆区创建内存!
        m_Height = new int(*p.m_Height);
    }
    //析构代码，将堆区开辟的数据做释放
    ~Person(){
        if(m_Height != NULL)
        {
            cout << "析构函数，释放堆区内存！" << endl;
            delete m_Height;
            //防止野指针的出现，将其置空
            m_Height = NULL;
        }
    } 
};

int main(){
    //p1, p2都放在栈区，满足先进后出，p2先被释放
    Person p1(18, 180);
    cout << "p1年龄：" << p1.m_Age << "\t" << "p1身高：" << *p1.m_Height << endl;
    //如果利用编译器提供的拷贝构造函数，会做浅拷贝操作
    //浅拷贝带来的问题就是内存的重复释放！！
    //浅拷贝的问题要利用深拷贝来进行解决
    Person p2(p1);
    cout << "p2年龄：" << p1.m_Age << "\t" << "p2身高：" << *p1.m_Height << endl;
	return 0;
}
````

> 总结： 如果有属性在堆区开辟，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题



#### 4.2.6 初始化列表



__作用：__

Ｃ++提供了初始化列表语法，用来初始化属性

__语法：__　`构造函数():属性1(值1), 属性2(值2), ... {}`



__示例：__

````c++
#include <iostream>
using namespace std;

class Person{
public:
    int m_A;
    int m_B;
    int m_C;
    //传统初始化操作
    //Person(int a, int b, int c)
    //{
    //    m_A = a;
    //    m_B = b;
    //    m_C = c;
    //};
    //初始化列表初始化属性
    Person(int a, int b, int c): m_A(a), m_B(b), m_C(c){};
};

void test01(){
    //Person p(10, 20, 30);
    Person p(10, 20, 30);
    cout << "m_A = " << p.m_A << endl;
    cout << "m_B = " << p.m_B << endl;
    cout << "m_C = " << p.m_C << endl;
}

int main(){
    test01();
    return 0;
}
````



#### 4.2.7 类对象作为类成员

Ｃ++类中的成员可以是另一个类的对象，我们称该成员为对象成员

例如：

````c++
class A{}
class B{
public:
    A a;
}
````

B类中有对象Ａ作为成员，Ａ为对象成员

那么当创建Ｂ对象时，Ａ与Ｂ的构造和析构的顺序是谁先谁后呢？



__示例：__

````c++
#include <iostream>
#include <string>
using namespace std;


class Phone{
public:
    string m_PName;
    Phone(string Name){
        cout << "Phone的构造函数调用！" << endl;
        m_PName = Name;
    };
    ~Phone(){
        cout << "Phone的析构函数调用!" << endl;
    }
};

class Person
{
public:
    string m_Name;
    Phone m_Phone;
    Person(string name, string p): m_Name(name), m_Phone(p){
        cout << "Person的构造函数调用!" << endl;
    };
    ~Person(){
        cout << "Person的析构函数调用！" << endl;
    }
};
// 当其他类对象作为本类成员，构造时会先构造其他类对象，在构造自身
void test01(){
    Person p("张三", "iPhone X MAX"); 
    cout << p.m_Name << "拿着：" << p.m_Phone.m_PName << endl;
};

int main()
{
    test01();
    return 0;
}
````



#### 4.2.8 静态成员

静态成员是在成员变量和成员函数前加上关键字static

静态成员分为:

* 静态成员变量
  * __所有对象共享同一份数据__
  * 在编译阶段分配内存
  * 类内声明，类外初始化
* 静态成员函数
  * 所有对象共享同一份数据
  * 静态成员函数只能访问静态成员变量（静态成员函数无法访问非静态成员变量，由于无法区分到底是哪个对象的变量）



__示例1__：静态成员变量

```c++
class Person 
{
public:
    //静态成员变量：类内声明，类外初始化
    static string m_type;
    static void func(){
        cout << "物种为： " << m_type << endl;
    };
}
string Person::m_type = "灵长类动物";

void test(){
    //静态成员变量有两种访问方式
    //1、通过对象访问
    Person p;
    //2、通过类名访问
    p.func();
    Person::func();
}

int main(){
    test();
    return 0;
}
```

__示例2__：静态成员函数

```c++
# include <iostream>
# include <string>
using namespace std;

class Person
{
public:
    //静态成员变量
	static string m_type;
 	//非静态成员变量
    string m_name;
    //静态成员函数，只能访问静态成员变量
    static void func()
    {
        //cout << "姓名为： " << m_name << endl; // 静态成员函数不可以访问非静态成员												变量，无法区分到底是哪个对象上的变量 
        cout << "物种为： " << m_type << endl;
    }
private:
    //静态成员函数也是有访问权限的
    static void func2()
    {
        cout << "func2调用" << endl;
    }
}
//静态成员变量类外初始化
string Person::m_type = "灵长类动物";

void test()
{
    // 静态成员函数的访问方式
    //1、通过对象访问
    Person p;
    p.func();
    //2、通过类名访问
    Person::func();
}

int main(){
    test();
    return 0;
}
```



### 4.3 C++对象模型和this指针



#### 4.3.1 成员变量和成员函数分开存储



在C++中，类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上，非静态成员函数也不属于类的对象上

__示例__：

```c++
class Person{
public:
    int age; //非静态成员变量，属于类的对象上
    int static m_B; //静态成员变量，不属于类的对象上
    Person(int age){
        // this 指针指向被调用的成员函数所属的对象
        this -> age = age;
    }; //非静态成员函数，不属于类的对象上
    static void func1(){} //静态成员函数，不属于类的对象上
    Person& PersonAddAge(Person &p)
    {
        this -> age += p.age;
        //this 指向p2的指针，而*this指向的就是p2这个对象本体
        return *this;
    }

};
int Person::m_B = 10;


void test01(){
    Person p(10);
    Person p1(p);
    p1.PersonAddAge(p).PersonAddAge(p).PersonAddAge(p);
    cout << p1.age << endl;
    //空对象占用内存为：１
    //C++编译器会给每个空对象也分配一个内存空间，是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout << sizeof(p) << endl;
}

int main(){
    test01();
    return 0;
}
```



####  4.3.2 this 指针

通过4.3.1我们知道在C++中成员变量和成员函数是分开存储的，每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码。

那么问题是：这一块代码是如何区分哪个对象调用自己的呢？

c++通过提供特殊的指针，this指针，解决上述问题。__this指针指向被调用的成员函数所属的对象__

this指针是隐含每一个非静态成员函数内的一种指针

this指针不需要定义，直接使用即可



this指针的用途：

* 当形参哈成员变量同名的时候，可以用this指针来区分
* 在类的非静态成员函数中返回对象本身，可以使用return *this

__示例__：

```c++
class Person{
public:
    int age; //非静态成员变量，属于类的对象上
    int static m_B; //静态成员变量，不属于类的对象上
    //非静态成员函数，不属于类的对象上
    Person(int age){
        //1、this指针解决名称冲突
        // this 指针指向被调用的成员函数所属的对象
        this -> age = age;
    }; 
    //静态成员函数，不属于类的对象上
    static void func1(){} 
    Person& PersonAddAge(Person &p)
    {	
        //2、利用this指针返回对象本身
        this -> age += p.age;
        //this 指向p2的指针，而*this指向的就是p2这个对象本体
        return *this;
    }

};
int Person::m_B = 10;


void test01(){
    Person p(10);
    Person p1(p);
    //利用this指针返回对象本身，实现链式编程 
    p1.PersonAddAge(p).PersonAddAge(p).PersonAddAge(p);
    cout << p1.age << endl;
    //空对象占用内存为：１
    //C++编译器会给每个空对象也分配一个内存空间，是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout << sizeof(p) << endl;
}

int main(){
    test01();
    return 0;
}
```



#### 4.3.3 空指针访问成员函数

C++中空指针也是可以访问成员函数的，但是也要注意有没有用到this指针

如果用到this指针，需要加以判断保证代码的健壮性



__示例__：

````c++
class Person{
public:
    void showClassName()
    {
        cout << "this is Person class" << endl;
    }
    
    void showPersonAge()
    {
        //防止传入空指针需要加入如下的判断语句
        /***
        if(this == NULL){
            cout << "Age = " << this->m_Age << endl;
        }
        ***/
        cout << "Age = " << m_Age << endl;
    }
    int m_Age;
}

void test01()
{
    Person * p = NULL;
    p->showClassName();
    //报错，原因传入的指针是空指针
    p->showPersonAge();
}

int main()
{
    test01();
    return 0;
}
````



#### 4.3.4 const修饰成员函数

__常函数__：

* 成员函数后加cosnt后我们称为这个函数为常函数
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改

__常对象__：

* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数



__示例__：

```c++
// 常函数
class Person
{
public:
    void showPerson() const
    {
        //加了const关键字，属性不允许修改
        thie->m_B = 100;
        m_A = 100;
    }
	int m_A;
	mutable int m_B; //特殊变量，即使在常函数中也可以被修改
	void func()
    {
        m_A = 100;
    }
}

void test02()
{
    const Person p; //在对象前加const，变为常对象
    p.m_B = 100; //m_B是特殊值，在常对象下也可以修改
    //常对象只能调用常函数
    p.showPerson();
    //p.func(); //常对象不能调用普通的成员函数
}
```



### 4.4 友元

生活中你的家有客厅(Public)，有你的卧室(Private)

客厅所有来的客人都可以进去，你的卧室是私有的，只有你能进去

但是呢，你也可以允许你的好闺蜜好基友进去。

在程序里，有些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元技术

友元的目的就是让一个函数或者类访问另一个类中私有成员

友元的关键字为 `friend`



友元的三种实现方法

* 全局函数做友元
* 类做友元
* 成员函数做友元



#### 4.4.1 全局函数做友元

````c++
class Building
{
    //在类内加上friend进行声明
    friend void goodFriend(Building& building);
public:
    string m_SittingRoom;
    Building(){
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

private:
    string m_BedRoom;

};

//全局函数
void goodFriend(Building& building)
{
    cout << "好基友的全局函数正在访问: " << building.m_SittingRoom << endl;
    cout << "好基友的全局函数正在访问: " << building.m_BedRoom << endl;

}

void test01(){
    Building b;
    goodFriend(b);
}

int main(){
    test01();
    return 0;
}
````



#### 4.4.2 类做友元/成员函数作为友元

````c++
class Building
{
    //friend void goodFriend(Building& building);
    //类友元
    //friend class GoodFriend;
    //成员函数做友元
    friend void GoodFriend::visit();
    friend void goodFriend(Building& buliding);
public:
    Building();
    string m_SittingRoom;

private:
    string m_BedRoom;

};
//类外写成员函数
Building::Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
};

class GoodFriend
{
public:
    GoodFriend();
    void visit();
    Building* building;
};
//构造函数
GoodFriend::GoodFriend()
{
    //创建建筑物对象
    building = new Building;
};
void GoodFriend::visit()
{
     cout << "好基友正在访问: " << building -> m_SittingRoom << endl;
     cout << "好基友正在访问: " << building -> m_BedRoom << endl;
}
 
//全局函数
void goodFriend(Building& building)
{
    cout << "好基友的全局函数正在访问: " << building.m_SittingRoom << endl;
    cout << "好基友的全局函数正在访问: " << building.m_BedRoom << endl;

}

void test01(){
    GoodFriend g;
    g.visit();
    /*
    Building b;
    goodFriend(b);
    */
}

int main(){
    test01();
    return 0;
}
````



### 4.5 运算符重载

预算法重载概念： 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型



#### 4.5.1 加号运算符重载

作用：实现两个自定义数据类型相加的运算

```c++
//加号运算符重载


class Data
{
public:
    int m_A, m_B;
    Data(){};
    Data(int a, int b);
 //   Data operator+(Data &d);
};

Data::Data(int a, int b)
{
    m_A = a;
    m_B = b;
}
//1、成员函数重载加号
//Data Data::operator+(Data &d)
//{
//    Data temp;
//    temp.m_A = d.m_A + this->m_A;
//    temp.m_B = d.m_B + this->m_B;
//    return temp;
//};

//2、全局函数重载加号
Data operator+(Data &d1, Data &d2)
{
    Data temp;
    temp.m_A = d1.m_A + d2.m_A;
    temp.m_B = d1.m_B + d2.m_B;
    return temp;
}

//运算符重载也可以发生函数重载
Data operator+(Data &d, int num)
{
    Data temp;
    temp.m_A = d.m_A + num; 
    temp.m_B = d.m_B + num; 
    return temp;
}
//左移运算符重载
ostream& operator<<(ostream &cout, Data &d)
{
    cout << "m_A = " << d.m_A << "\t" << "m_B = " << d.m_B;
    return cout; //链式编程思想
}

//递增运算符重载
class MyInteger
{
public:
    MyInteger(){};

private:
    int m_Num;
    
};

MyInteger::MyInteger(){
    m_Num = 0;
}
void test01()
{
    Data d1(10, 20);
    Data d2(30, 40);
    Data d3 = d1 + d2;
    Data d4 = d3 + 10;
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    cout << d4 << endl;
    //cout << d3.m_A << endl;
    //cout << d3.m_B << endl;
    //cout << d4.m_A << endl;
    //cout << d4.m_B << endl;
}

int main()
{
    test01();
    return 0;
}
```



#### 4.5.2 左移运算符重载

作用：可以输出自定义数据类型

```c++
//左移运算符重载

class Data
{
public:
    int m_A;
    int m_B;

    Data(int, int);
    
    //无法利用成员函数实现左移运算符重载，因为无法使得cout在左侧
    ostream& operator<<(ostream& cout)
    {
        cout << "m_A = " << this->m_A << endl;
        cout << "m_B = " << this->m_B << endl;
    }
    
};

Data::Data(int a, int b)
{
    m_A = a;
    m_B = b;
}

//重载左移运算符
ostream& operator<<(ostream& cout, Data &d)
{
    cout << "m_A = " << d.m_A << endl;
    cout << "m_B = " << d.m_B << endl;
    return cout;
}

void test01(){
    Data d1(10, 100);
    cout << d1 << endl;
    //使用成员函数实现的左移运算符重载无法实现cout在左侧
    d1 << cout;
}

int main(){
    test01();
    return 0;
}
```



#### 4.5.3  递增运算符重载

作用：通过重载递增运算符，实现自己的整型数据

```c++
class MyInt
{
    friend ostream& operator<<(ostream&, MyInt);
public:
    MyInt(int);
    //前置递增
    MyInt& operator++();
    //后置递增
    MyInt operator++(int);

private:
    int m_Num;
};

MyInt::MyInt(int a)
{
    m_Num = a;
}
MyInt& MyInt::operator++()
{
    m_Num++;
    return *this;
}

MyInt MyInt::operator++(int)
{
    //先记录当时结果
    MyInt temp = *this;
    //后递增
    m_Num++;
    //最后返回记录结果
    return temp;
}

//重载左移运算符
ostream& operator<<(ostream& cout, MyInt a)
{
    cout << a.m_Num << endl;
    return cout;
}

void test01()
{
    MyInt a(10);
    cout << a << endl;
    cout << ++a << endl;
    cout << a << endl;
    cout << a++ << endl;
    cout << a << endl;
}

int main()
{
    test01();
    return 0;
}
```



#### 4.5.4 赋值运算符重载

c++编译器至少给一个类添加4个函数

1、默认构造函数（无参，函数体为空）

2、默认析构函数（无参，函数体为空）

3、默认拷贝构造函数，对属性进行值拷贝

4、赋值运算符 operator=，对属性进行值拷贝 



如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题

__示例__：

```c++
class Data
{
public:
    int m_A;
    int* m_B;
    Data()
    {
        cout << "无参构造函数调用" << endl;
    };
    Data(int, int);
    // Data(const Data& d);
    Data& operator=(Data& d);
    ~Data();
};
Data::Data(int a, int b)
{
    m_A = a;
    m_B = new int(b);
};
// Data::Data(const Data& d)
// {
//     cout << "拷贝构造函数调用" << endl;
//     m_A = d.m_A;
//     m_B = new int(*d.m_B);
// };
Data::~Data()
{
    cout << "析构函数调用" << endl;
    if(m_B != NULL)
    {
        delete m_B;
        m_B = NULL;
    };
};

Data& Data::operator=(Data& a)
{
    // if (this->m_B != NULL)
    // {
    //     delete this->m_B;
    //     this->m_B = NULL;
    // };
    cout << "等号运算符重载！" << endl;
    this->m_A = a.m_A;
    this->m_B = new int(*a.m_B);
    return *this;
};

void test01()
{
    Data d(100, 125);
    Data d1(10, 100);
    Data d2;
    d = d2 = d1;
};

int main()
{
    test01();
    return 0;
}
```





####  4.5.5 关系运算符重载

__作用__：重载关系运算符，可以让两个自定义类型对象进行对比操作

__示例__：

```c++
class Data
{
public:
    Data(int, int);
    bool operator==(Data& d);
    int m_A, m_B;
};

Data::Data(int a, int b)
{
    m_A = a;
    m_B = b;
}

bool Data::operator==(Data& d)
{
    cout << "调用关系运算符重载函数" << endl;
    if((d.m_A == this->m_A)&&(d.m_B == this->m_B))
    {
        return true;
    }
    return false;
}

string isequal(Data& d1, Data& d2)
{
    string result;
    if (d1 == d2)
    {
        result = "True";
    }
    else
    {
        result = "False";
    }
    return result;
}

void test01()
{
    Data d1(10, 100);
    Data d2(10, 100);
    Data d3(5, 100);
    cout << isequal(d1, d2) << endl;
    cout << isequal(d1, d3) << endl;
}

int main()
{
    test01();
    return 0;
}
```



#### 4.5.6 函数调用运算符重载

* 函数调用运算符（）也可以重载
* 由于重载后使用的方式非常像函数的调用，因此称为仿函数
* 仿函数没有固定的写法，非常灵活



__示例__：

````c++
class MyPrint{
public:
    void operator()(string test)
    {
        cout << test << endl;
    }
};

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1+num2;
    }
};

void test01()
{
    MyPrint myprint;
    myprint("hello world");
    cout << MyAdd()(15, 16) << endl; //类型名+小括号=匿名对象，调用后立即释放
}

int main()
{
    test01();
    return 0;
}
````



### 4.6 继承

__继承是面向对象的三大特性之一__

有些类与类之间存在特殊的关系，我们发现定义这些类的时候，下级别的成员除了拥有上一级的共性，还有自己的特性，这个时候我们就可以考虑利用继承的技术，减少重复代码。



#### 4.6.1 继承的基本语法

例如我们看到很多网站中，都有公共的头部、公共的底部、甚至公共的左侧列表，只有中心内容不同，接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处。

__普通实现__：

````c++
Java页面
class Java
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++、...（公共分类列表）" << endl;
    }
    void content()
    {
        cout << "Java学科视频" << endl;
    }
};
//Python 页面
class Python
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++、...（公共分类列表）" << endl;
    }
    void content()
    {
        cout << "python学科视频" << endl;
    }
};
//c++页面
class Cpp
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++、...（公共分类列表）" << endl;
    }
    void content()
    {
        cout << "C++学科视频" << endl;
    }

};
````



利用继承：

```c++
/*
使用继承写法如下：
继承的好处：减少重复代码
继承的语法：class 子类：继承方式 父类
子类 也称为 派生类
父类 也称为 基类
*/

class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++、...（公共分类列表）" << endl;
    }
};

//Java页面
class Java : public BasePage
{
public:
    void content(){
        cout << "Java学科视频" << endl;
    }

};

//Python页面
class Python : public BasePage
{
public:
    void content(){
        cout << "python学科视频" << endl;
    }

};

//C++页面
class Cpp : public BasePage
{
public:
    void content(){
        cout << "Cpp学科视频" << endl;
    }

};
```



#### 4.6.2 继承方式

继承的语法：`class 子类 : 继承方式 父类`

继承的三种方式：

* 公共继承
* 保护继承
* 私有继承

![](/home/vansikey/Pictures/Screenshot from 2019-09-27 11-01-50.png)

#### 4.6.3 继承中的对象模型

__问题__：从父类继承过来的成员，哪些属于子类对象中？

__示例__：

````c++
class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};


class Son:public Base1
{
public:
    void func()
    {
        m_A = 10; //父类中公共权限成员 到子类中依然是公共权限
        m_B = 10; //父类中保护权限成员 到子类中依然是保护权限
        //m_C = 10; //父类中私有权限成员 子类无法访问
    }
    int m_D;

};

void test01()
{
    cout << "size of son = " << sizeof(Son) << endl;
}

//最后的结果是16，父类中所有非静态成员属性都会被子类继承下去
//父类中私有成员属性，是被编译器隐藏了，因此是访问不到，但是确实被继承下去了。

int main(){
    test01();
    return 0;
}
````

> 在windows系统下，利用开发人员提示工具可以查看对象模型，具体步骤为
>
> 1、跳转盘符
>
> 2、跳转文件路径，cd ..具体路径下
>
> 3、查看命令： cl /d1 reportSingleClassLayout类名 文件名 



#### 4.6.4 继承中的构造和析构顺序

子类继承父类后，当创建子类对象，也会调用父类的构造函数

问题：父类和子类的构造和析构顺序是谁先谁后呢？

__示例__：

````c++
class BaseClass
{
public:
    BaseClass()
    {
        cout << "父类中的构造函数" << endl;
    }
    ~BaseClass()
    {
        cout << "父类中的析构函数" << endl;
    }
};

class SonClass : public BaseClass
{
public:
    SonClass()
    {
        cout << "子类中的构造函数" << endl;
    }
    ~SonClass()
    {
        cout << "子类中的析构函数" << endl;
    }

};


int main()
{
    SonClass s;
    return 0;
}
//--------------------------------------------------
//结果如下:
父类中的构造函数
子类中的构造函数
子类中的析构函数
父类中的析构函数
````



#### 4.6.5继承中同名成员处理方式

问题：当子类与父类中出现同名成员，如何通过子类对象，访问到子类或父类中同名的数据呢?

* 访问子类同名成员，直接访问即可
* 访问父类同名成员，需要加作用域

__示例__：

````c++
class DataBase
{
public:
    int m_A;
    int m_B;
    DataBase()
    {
        m_A = 100;
        m_B = 100;
    }
    void func()
    {
        cout << "父类中的成员函数" << endl;
    }
    void func(int a)
    {
        cout << "父类中重载的成员函数" << endl;
    }

};

class Data1 :public DataBase
{
public:
    int m_A;
    int m_B;
    int m_C;
    Data1()
    {
        m_A = 200;
        m_B = 200;
        m_C = 50;
    }
    void func()
    {
        cout << "子类中的成员函数" << endl;
    }
};

void test01()
{
    //如果子类出现和父类中同名的成员函数或属性，
    //子类中的同名成员会隐藏掉父类中所有同名成员函数
    //如果想访问到父类中被隐藏的同名成员函数，需要加作用域 
    Data1 d;
    cout << "size of data1: " << sizeof(Data1) << endl;
    cout << "Data1 下的 m_A = " << d.m_A << endl;
    cout << "DataBase 下的 m_A = " << d.DataBase::m_A << endl;
    //调用子类中的成员函数
    d.func();
    //调用父类中的成员函数
    d.DataBase::func();
    //调用父类中重载的成员函数
    d.DataBase::func(100);
}

int main()
{
    test01();
    return 0;
}
````

总结：

1、子类对象可以直接访问到子类中同名成员

2、子类对象加作用域可以访问到父类同名成员

3、当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类	  中同名函数



#### 4.6.6 继承同名静态成员处理方式

问题：继承中同名静态成员在子类对象上如何进行访问？

静态成员和非静态成员出现同名，处理方式一致

* 访问子类同名成员，直接访问即可
* 访问父类同名成员，需要加作用域



#### 4.6.7 多继承语法

C++允许__一个类继承多个类__

语法：`class 子类：继承方式 父类1，继承方式 父类2 ...`

多继承可能会引发父类中有同名成员出现，需要加作用域区分

__C++实际开发中不建议用多继承__



#### 4.6.8 菱形继承

__菱形继承概念__：

​		两个派生类继承同一个基类

​		又有某个类同事继承这两个派生类

​		这种继承被称为菱形继承，或者砖石继承



__典型菱形继承案例__：

​				![](/home/vansikey/Pictures/Screenshot from 2019-09-29 09-58-26.png)

__菱形继承问题__：



​		1、羊继承了动物的数据，驼同样继承了动物的数据，当羊驼使用数据时，就会产生二义性。

​		2、羊驼继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以			  了。

__解决方法__：

​		使用虚继承，语法为：`class 子类 :virtual 继承方式 父类 {};`

__示例__：

```c++
class Animal
{
public:
	int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal{};
class Camel : virtual public Animal{};
class Alpaca : public Sheep, public Camel {};

void test01()
{
    Alpaca ap;
    ap.Sheep::m_Age = 5;
    ap.Camel::m_Age = 8;
    
    cout << "ap.Sheep::m_Age = " << ap.Shepp::m_Age << endl;
    cout << "ap.Camel::m_Age = " << ap.Camel::m_Age << endl;
    cout << "ap.m_Age = " << ap.m_Age << endl;
}

int main()
{
    test01();
    return 0;
}
```



总结：

* 菱形继承带来的主要问题是子类继承了来自父类的两份同样数据，导致资源浪费
* 利用虚继承可以解决菱形继承问题





### 4.7 多态

#### 4.7.1 多态的概念



__多态是C++面向对象三大特性之一__

多态分为两类

*  静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
* 动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态的区别：

* 静态多态的函数地址早绑定 - 编译阶段确定函数地址
* 动态多态的函数地址晚绑定 - 运行阶段确定函数地址

下面通过案例来说明：

```c++
class Animal
{
public:
    //virtual关键字，将成员函数变成虚函数
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
```

总结：

多态满足条件

* 有继承关系
* 子类重写父类中的虚函数

多态使用条件

* 父类指针\引用指向子类对象

重写： 函数返回值类型，函数名 参数列表 完全一致为重写（__重写__不等于__重载__）

__原理如下图__：

父类中的虚函数指针`{vfptr}`(占4个字节) 指向对应的虚函数表`Animal::$vftable`，该表中记录了虚函数的地址`&Animal::speak`。

![](/home/vansikey/Pictures/动态多态原理.png)

当用子类进行继承时，子类会继承父类中的虚函数指针，与虚函数表。

![](/home/vansikey/Pictures/动态多态原理_2.png)

当在子类重写父类的虚函数时，子类中的虚函数表所记录的虚函数地址将会变为子类虚函数地址

![](/home/vansikey/Pictures/动态多态原理_3.png)



#### 4.7.2 多态案例一 ——计算器类

案例描述：

分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类



多态的优点：

* 代码组织结构清晰
* 可读性强
* 利于前期和后期的扩展以及维护



__示例__：

````c++
//定义一个计算器基类
class AbstractCalculator
{
public:
    int m_Num1;
    int m_Num2;
    virtual int getResult()
    {
        return 0;
    }
};

//加法运算
class AddCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

//乘法运算
class MulCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

//减法运算
class SubCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 - m_Num2;
    }
};


void test01()
{
    //利用基类指针指向子类对象
    AbstractCalculator* abs;
    abs = new AddCalculator;
    
    abs->m_Num1 = 10;
    abs->m_Num2 = 20;
    cout << abs->m_Num1 << " + " << abs->m_Num2 << " = " << abs->getResult() << endl;
    //new在堆区的数据，用完记得销毁(清空数据，但是指针的类型不变)
    delete abs;

    abs = new MulCalculator;
    cout << abs->m_Num1 << " * " << abs->m_Num2 << " = " << abs->getResult() << endl;
    delete abs;

    abs = new SubCalculator;
    cout << abs->m_Num1 << " - " << abs->m_Num2 << " = " << abs->getResult() << endl; 
    delete abs;
    
}

int main()
{
    test01();
    return 0;
}
````



#### 4.7.2 纯虚函数和抽象类

在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容

因此可以将虚函数改写为__纯虚函数__



纯虚函数的语法：`virtual 返回值类型 函数名（参数列表）= 0;`



当类中有纯虚函数，这个类也称为__抽象类__



__抽象类的特点__：

* 无法实例化对象
* 子类必须重写抽象类中的纯虚函数，否则也属于抽象类



__示例__：

```c++
class AbstractCalculator
{
public:
    int m_Num1;
    int m_Num2;
    virtual int getResult() = 0; //纯虚函数
};

class AddCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 + m_Num2;
    }
};


class MulCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 * m_Num2;
    }
};


class SubCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 - m_Num2;
    }
};


void test01()
{
    AbstractCalculator* abs = new AddCalculator;
    abs->m_Num1 = 10;
    abs->m_Num2 = 20;
    cout << abs->m_Num1 << " + " << abs->m_Num2 << " = " << abs->getResult() << endl;
    delete abs;

    abs = new MulCalculator;
    cout << abs->m_Num1 << " * " << abs->m_Num2 << " = " << abs->getResult() << endl;
    delete abs;

    abs = new SubCalculator;
    cout << abs->m_Num1 << " - " << abs->m_Num2 << " = " << abs->getResult() << endl; 
    
}

int main()
{
    test01();
    return 0;
}
```



#### 4.7.3 虚析构和纯虚析构



多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用子类的析构代码



解决方式：将父类中的析构函数改为__虚析构__或者__纯虚析构__



虚析构和纯虚析构共性：

* 可以解决父类指针释放子类对象
* 都需要有具体的函数实现

虚析构和纯虚析构区别：

* 如果是纯虚析构，该类属于抽象类，无法实例化对象



虚析构语法：

`virtual ~类名(){}`

纯虚析构语法：

`virtual ~类名() = 0`

`类名::~类名(){}`



### 5 文件操作

程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放

通过__文件可以将数据持久化__

C++中对文件操作需要包含头文件`<fstream>`



文件类型分为两种：

1、__文本文件__：文件以文本的ASCII码形式存储在计算机中

2、__二进制文件__：文件以文本的__二进制__形式存储在计算机中，用户一般不能直接读懂他们



操作文件的三大类：

1、ofstream：写操作

2、ifstream：读操作

3、fstream ： 读写操作



#### 5.1.1 写文件

写文件步骤如下：

1、包含头文件

​	`#include <fstream>`

2、创建流对象

​	`ofstream ofs;`

3、打开文件

​	`ofs.open("文件路径"， 打开方式);`

4、写数据

​	`ofs << "写入的数据";`

5、关闭文件

​	`ofs.close();`



文件的打开方式 

| 打开方式    | 解释                       |
| ----------- | -------------------------- |
| ios::in     | 为读而打开文件             |
| ios::out    | 为写文件而打开             |
| ios::ate    | 初始位置：文件尾           |
| ios::app    | 追加方式写文件             |
| ios::trunc  | 如果文件存在先删除，再创建 |
| ios::binary | 二进制方式打开文件         |

__注意__：文件打开方式可以配合使用，利用 | 操作符号

__例如__：用二进制方式写文件 `ios::binary | ios::out`



__示例__：

```c++
# include <iostream>
# include <fstream>
using namespace std;


void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs << "天青色等烟雨，而我在等你" << endl;
    ofs << "炊烟袅袅升起，隔江千万里" << endl; 
    ofs.close();
}

int main()
{
    test01();
    return 0;
}
```



#### 5.1.2 读文件

读文件与写文件步骤类似，但是读取方式相对于写文件比较多



读文件步骤如下：

1、包含头文件

​	`#include <fstream>`

2、创建流对象

​	`ifstream ifs;`

3、打开文件并判断文件是否打开成功

​	`ifs.open("文件路径", 打开方式);`

4、读数据

​	四种方式读取

5、关闭文件

​	`ifs.close();`

 

__示例__：

````c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void test01()
{
    //1、包含头文件
    //2、创建流对象
    ifstream ifs;

    //3、打开文件 并判断是否打开成功
    ifs.open("test.txt", ios::in);

    if (!ifs.is_open()){
        cout << "文件打开失败"  << endl;
        return ;
    }
    
    //4、读数据
    // 第一种方式
    // char buf[1024] = { 0 };
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }
    
    // 第二种
    // char buf[1024] = { 0 };
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }

    //第三种
    string buf;
    while (getline(ifs, buf))
    {
        cout << buf << endl;
    }

    //5、关闭文件
    ifs.close();
}

int main()
{
    test01();
    return 0;
}
````

总结：

* 读文件可以利用 ifstream，或者 fstream 类
* 利用is_open()函数可以判断文件是否打开成功
* close()关闭文件



### 5.2 二进制文件

以二进制的方式对文件进行读写

打开方式要制定为 `ios::binary`



#### 5.2.1 写文件

而精致方式写文件主要利用流对象调用成员函数write

函数原型：`ostream& write(const char* buffer, int len);`

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数



__示例__：

````c++
#include <iostream>
#include <fstream>
using namespace std;


class Data
{
public:
    int m_Num1;
    int m_Num2;
};


void test01()
{
   //1、包含头文件
   //2、创建流对象
   ofstream ofs;

   //3、打开文件
   ofs.open("Data.txt", ios::out | ios::binary);

   //4、写文件
   Data d = {18, 1235};
   ofs.write((const char *)&d, sizeof(Data));

   //5、关闭文件
   ofs.close();
}

int main()
{
    test01();
    return 0;
}
````





#### 5.2.2 读文件

二进制方式读文件主要利用流对象调用成员函数read

函数原型：`istream& read(char *buffer, int len);`

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

__示例__：

```c++
#include <iostream>
#include <fstream>
using namespace std;


class Data
{
public:
    int m_Num1;
    int m_Num2;
};

void test01()
{
    ifstream ifs;

    ifs.open("Data.txt", ios::in|ios::binary);

    if(!ifs.is_open())
    {
        cout << "读取文件失败" << endl;
        return;
    }

    Data d;

    ifs.read((char *)&d, sizeof(Data));

    cout << d.m_Num1 << endl;
    cout << d.m_Num2 << endl;

    ifs.close();

}

int main()
{
    test01();
    return 0;
}

```



# C++ 提高编程

* 本阶段主要针对C++__泛型编程__和STL技术做详细讲解，探讨C++更深层的使用

## 1 模板

### 1.1 模板的概念

### 1.2 函数模板

* C++另一种编程思想称为泛型编程，主要利用的技术就是模板
* C++提供两种模板机制：__函数模板__和__类模板__

#### 1.2.1 函数模板语法

函数模板作用：

建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个__虚拟的类型__来代表。



__语法__：

```c++
template<typename T>
函数声明或定义
```

__解释__：

template --- 声明创建模板

typename --- 表面其后面的符号是一种数据类型，可以用class代替

T --- 通用的数据类型，名称可以替换，通常为大写字母 



__示例__：

```c++
#include <iostream>
using namespace std;


//函数模板

//交换两个数(整型、浮点型...)
template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    double a = 3.14, b = 2.56;
    Swap(a, b); //自动类型推导
    //显示指定类型
    //Swap<double>(a, b)
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
```



#### 1.2.2 函数模板注意事项

注意事项：

* 自动类型推导，必须推导出一致的数据类型T，才可以使用
* 模板必须要确定出T的数据类型，才可以使用



#### 1.2.3 函数模板案例

案例描述：

* 利用函数模板封装一个排序函数，可以对__不同数据类型数组__进行排序
* 排序规则冲大到小，排序算法为__选择排序__
* 分别利用__char数组__和__int数组__进行测试



__示例__：

````c++
#include <iostream>
using namespace std;


//函数模板

//交换两个数(整型、浮点型...)
template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

/*
选择排序：
原理：首先在未排序序列中找到最大(小)元素，存放到排序序列的起始位置，然后再从剩余未排序序列中继续寻找最大(小)元素，然后放到已排序序列的末尾，以此类推直到所有元素均排序完毕。
*/
template<typename T>
void mysort(T arr[], int len)
{
    for (int i = 0;i<len;i++)
    {
        int max = i;
        for (int j = i;j<len;j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            Swap<T>(arr[i], arr[max]);
        }
    }
}

int main()
{
    double a = 3.14, b = 2.56;
    Swap(a, b); //自动类型推导
    //显示指定类型
    //Swap<double>(a, b)
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // int arr[] = {1, 5, 9, 2, 10};
    // int len = sizeof(arr)/sizeof(int);

    char charArr[] = "acdebf";
    int len = sizeof(charArr) / sizeof(char);
    
    mysort<char>(charArr, len);
    for (int i = 0;i<len;i++)
    {
        cout << charArr[i] << " ";
    }
    cout << endl;
    return 0;
}
````



#### 1.2.4 普通函数与函数模板的区别

__普通函数与函数模板区别__：

* 普通函数调用时可以发生自动类型推到（__隐式类型转换__）
* 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
* 如果利用显示指定类型的方式，可以发生隐式类型转换



#### 1.2.5 普通函数与函数模板的调用规则

调用规则如下：

1、如果函数模板和普通函数都可以实现，优先调用普通函数

2、可以通过空模板参数列表`func<>(实参列表)` 来强调函数模板的调用

3、函数模板也可以发生重载

4、如果函数模板可以产生更好的匹配，优先调用函数模板



总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性。



#### 1.2.6 模板的局限性

__局限性__：

* 模板的通用性并不是万能的



__例如__：

````c++
template<typename T>
void f(T a, T b)
{
	a = b;
}
````

在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了



总结：

* 利用具体化的模板，可以解决自定义类型的通用化
* 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板



### 1.3 类模板

 #### 1.3.1 类模板语法

类模板作用：

* 建立一个通用类，类中的成员数据类型可以不具体制定，用一个__虚拟的类型__来代表。



__语法：__

```c++
template<typename T1, typename T2, ...>
类
```

 

#### 1.3.2 类模板与函数模板区别

类模板与函数模板区别主要有两点：

1、类模板没有自动类型推导的使用方式

2、类模板在模板参数列表中可以有默认参数，如`template<class T1, class T2 = int>`



#### 1.3.3 类模板中成员函数创建时机

类模板中成员函数和普通类中成员函数创建时机是有区别的：

* 普通类中的成员函数一开始就可以创建
* 类模板中的成员函数在调用时才创建



__示例__：

````C++
#include <iostream>
#include <string>
using namespace std;

//类模板的成员函数创建时机

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};


class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};


template <class T>
class MyClass
{
public:
    T obj;

    //类模板中的成员函数
    void func1()
    {
        obj.showPerson1();
    }
    void func2()
    {
        obj.showPerson2();
    }
};


int main()
{
    MyClass<Person1> mc;
    mc.func1();
    return 0;

}
````



#### 1.3.4 类模板对象做函数参数

学习目标：

* 类模板实例化出的对象，向函数传参的方式



一共有三种传入方式：

​	1、指定传入的类型 	--- 直接显示对象的数据类型

​	2、参数模板化			 --- 将对象中的参数变为模板进行传递

​	3、整个类模板化		 --- 将这个对象类型 模板化进行传递

> 可以使用typeid(T).name()来查看数据类型



#### 1.3.5 类模板与继承

当类模板碰到继承时，需要注意一下几点：

* 当子类继承的父类是一个类模板时，子类在声明的时候，要指出父类中T的类型
* 如果不指定，编译器无法给子类分配内存
* 如果想灵活制定出父类中T的类型，子类也需要变为类模板



__示例__：

````c++
#inculde<iostream>
using namespace std;

//类模板与继承
template<class T>
class Base
{
public:
    T m;
};

//class Son : public Base //错误，必须要知道父类中T的类型，才能继承给子类
class Son : public Base<int>
{};

//如果想要灵活的指定父类中的类型，子类也需要变成类模板
template<class T1, class T2>
class Son2:public Base<T2>
{
T1 obj;
};
````



#### 1.3.6 类模板成员函数的类外实现

学习目标：能够掌握类模板中的成员函数类外实现



__示例__：

````c++
# include <iostream>
using namespace std;

template<class T1, class T2>
class Data
{
public:
    T1 m_Num1;
    T2 m_Num2;
    void Data(T1 a, T2 b);
    void showData();
};

//构造函数 类外实现
template<class T1, class T2>
void Data<T1, T2>::Data(T1 a, T2 b)
{ 
    this->m_Num1 = a;
    this->m_Num1 = b;
}

//成员函数 类外实现
template<class T1, class T2>
void Data<T1, T2>::showData()
{
    cout << "m_Num1 = " << this->m_Num1 << endl;
    cout << "m_Num2 = " << this->m_Num2 <<endl;
}

````



#### 1.3.7 类模板分文件编写



问题：

* 类模板中成员函数创建时机是在调用阶段，导致份文件编写时链接不到

解决：

* 解决方式1：直接包含.cpp源文件(一般不这么做)
* 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制



#### 1.3.8 类模板与友元



全局函数类内实现 - 直接在类内声明友元即可

全局函数类外实现 - 需要提前让编译器知道全局函数的存在







## 2 STL初识

### 2.1 STL基本概念

* STL(Standard Template Library, 标准模板库)

* STL从广义上分为__容器(container)、算法(algorithm)、迭代器(iterator)__
* __容器__和__算法__之间通过__迭代器__进行无缝连接
*  STL几乎所有的代码都采用了模板类或者模板函数



### 2.3 STL六大组件

STL大体可以分为六大组件，分别是：__容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器__



1、容器：各种数据结构，如vector、list、deque、set、map等，用来存放数据

2、算法：各种常用的算法，如sort、find、copy、for_each等

3、迭代器：扮演了容器与算法之间的胶合剂

4、仿函数：行为类似函数，可作为算法的某种策略

5、适配器：一种用来修饰容器或者仿函数或迭代器接口的东西

6、空间配置器：负责空间的配置与管理



### 2.4 STL中容器、算法、迭代器

#### 2.4.1 vector存放内置数据类型

```c++
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;


void myPrint(int val)
{
    cout << val << endl; 
}

void test01()
{
    //创建一个vector容器，
    vector<int> v;

    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // //通过迭代器访问vector中的数据
    // vector<int>::iterator itBegin = v.begin(); //起始迭代器，指向容器中第一个元素
    // vector<int>::iterator itEnd = v.end(); // 结束迭代器，指向容器中最后一个元素的后一位

    // //第一种遍历方式
    // while(itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }
    //第二种遍历方式
    // for(vector<int>::iterator it = v.begin();it != v.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    //第三种遍历方式，使用STL中提供的遍历算法
    for_each(v.begin(), v.end(), myPrint);
    
}

int main()
{
    test01();
    return 0;
}
```





### 2.5 string 基本概念

__本质__：

* string 是 C++风格的字符串，而string本质上是一个类

__stirng和char * 区别：__

* char * 是一个指针
* string 是一个类，类内部封装了char * ，管理这个字符串，是一个char * 型的容器

__特点：__

string类内部封装了很多成员方法

例如：查找find，拷贝copy，删除delete，替换replace，插入insert

string管理cahr *所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责



#### 2.5.1 string构造函数

构造函数原型：

* `string();` 									//创建一个空的字符串，例如：string str;

  `string(const char * s);`		//使用字符串s初始化

* `string(const string& str);`  //使用一个string对象初始化另一个string对象

* `string(int n, char c);`          //使用n个字符c初始化



### 3.1 vector容器

#### 3.1.1 vector基本概念

__功能：__

* vector数据结构和__数组__非常相似，也称__单端数组__

__vector与普通数组区别：__

* 不同之处在于数组是静态空间，而vector是__动态扩展__



__动态扩展：__

* 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间



![](/home/vansikey/Pictures/Screenshot from 2019-10-06 15-59-33.png)

* vector容器的迭代器是支持随机访问的迭代器



#### 3.2.2 vector构造函数



__功能描述：__

* 创建vector容器



__函数原型：__

* `vector<T> v;` 										//采用模板实现类实现，默认构造函数
* `vector(v.begin(), v.end());`          //将v[begin(), end()) （前闭后开）区间中的元素拷贝给本身。
* `vector(n, elem);`                                 //构造函数将n个elem拷贝给本身
* `vector(const vector &vec);`            //拷贝构造函数



#### 3.2.3 vector赋值操作

__功能描述：__

* 给vector容器进行赋值



__函数原型：__

* `vector& oprator=(const vector &vec);`  	//重载等号操作符
* `assign(beg, end);`                                              //将[beg, end)区间中的数据拷贝赋值给本身
* `assign(n, elem);`                                                 //将n个elem拷贝赋值给本身



#### 3.2.4 vector容量和大小

__功能描述：__

* 对vector容器的容量和大小操作



__函数原型：__

* `empty();`                                   // 判断容器是否为空

* `capacity();`                             // 容器的容量

* `size();`                                     // 返回容器中元素的个数

* `resize(int num);`                   // 重新指定容器的长度为num，若容器变长，则以默认值填充新位置

  ​													  // 如果容器变短，则末尾超出容器长度的元素被删除

* `resize(int num, elem);`       // 重新制定容器的长度为num，若容器边长，则以elem填充新位置。

  ​													  // 如果容器变短，则末尾超出容器长度的元素被删除



#### 3.2.5 vector插入和删除

__功能描述：__

* 对vector容器进行插入、删除操作



__函数原型：__

* `push_back(ele);`                                         //尾部插入元素ele
* `pop_back();`                                                 //删除最后一个元素
* `insert(const_iterator pos, ele);`      //迭代器指向位置pos插入元素ele
* `insert(const_iterator pos, int count, ele);`     //迭代器指向位置pos插入count个元素ele
* `erase(const_iterator pos);`                   //删除迭代器指向的元素
* `erase(cosnt_iterator start, const_iterator end);`    //删除迭代器从start到end之间的元素
* `clear();`                                                        //删除容器中所有元素



#### 3.2.6 vector数据存取

__功能描述：__

* 对vector中的数据的存取操作



__函数原型：__

* `at(int idx);`                          //返回索引idx所指的数据
* `operator[];`                            //返回索引idx所指的数据
* `front();`                                  //返回容器中第一个数据元素
* `back();`                                    //返回容器中最后一个数据元素



#### 3.2.7 vector互换容器

__功能描述：__

* 实现两个容器内元素进行互换

__函数原型：__

* `swap(vec);`      //将vec与本身的元素互换



__实际用途：__ 

巧用`swap()` 可以收缩内存空间



__示例：__

````c++
vector<int> v;
for (int i=0; i<100000; i++)
{
    v.push_back(i);
}
v.resize(3);
//收缩内存
vector<int>(v).swap(v); //匿名对象
````



#### 3.2.8 vector预留空间

__功能描述：__

* 减少vector在动态扩展容量时的扩展次数



__函数原型：__

* `reserve(int len);`  //容器预留len个元素长度，预留位置不初始化，元素不可访问



__示例：__

```c++
# include <vector>

void test01()
{
    vector<int> v;
    //预留空间
    v.reserve(100000);
    
    int num = 0;
    int *p = NULL;
    for (int i=0; i<100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "分配内存空间次数: " << num << endl;
}
```

总结：如果数据量较大，可以一开始就利用reserve预留空间，以免动态内存扩展时多次分配内存空间。





### 3.2 deque容器

#### 3.3.1 deque容器基本概念



__功能：__

* 双端数组，可以对头端进行插入删除操作

