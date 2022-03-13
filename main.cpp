#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class A {
public:
    void fun(int a) { cout << "fun with int" << endl; }
    void fun(double a) { cout << "fun with double" << endl; }
    // bool fun(int a) { cout << "fun with int return bool" << endl; }  // 无法重载仅按返回值类型区分的函数
    void fun(int a, float b) { cout << "fun with int and float" << endl; }
    void fun(float a, int b) { cout << "fun with float and int" << endl; }
    virtual void fun(int a, float b)  const { cout << "fun with int and float const" << endl; }  //编译通过，如何调用？
};

void main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    A* a = new A;
    a->fun(1);
    a->fun(1.009);
    a->fun(1, 1.09);
    a->fun(1.09, 1);
    return;
}