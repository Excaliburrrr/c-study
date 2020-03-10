#include <iostream>
using namespace std;

int& mySum()
{
  static int num = 10;
  return num;
}

void test()
{
  int a = 10;
  int e = 200;
  cout << "address a: " << &a << endl;
  cout << "address e: " << &e << endl;
}

int main()
{
  /*
  int &ref = mySum();
  mySum() = 1000;
  cout << "ref = " << ref << endl;
  */
  int b = 20;
  int c = 30;
  test();
  cout << "address b: " << &b << endl;
  cout << "address c: " << &c << endl;
  return 0;
}
