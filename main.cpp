#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class A {
public:
    void fun(int a) { cout << "class A fun with int" << endl; }
    void fun(double a) { cout << "class A fun with double" << endl; }  // 重载
    void fun(string str) { cout << "class A fun with string" << endl; }
    // bool fun(int a) { cout << "class A fun with int return bool" << endl; }  // 无法重载仅按返回值类型区分的函数
    void fun(int a, float b) { cout << "class A fun with int and float" << endl; }  // 重载
    void fun(float a, int b) { cout << "class A fun with float and int" << endl; }  // 重载
    virtual void fun(int a, float b)  const { cout << "class A virtual fun with int and float and char const" << endl; }  //编译通过，如何调用？
    virtual void fun(int a, float b, char c)  const { cout << "class A virtual fun with int and float and char const" << endl; }
};

class B : public A {
public:
    void fun(int a) { cout << "class B fun with int" << endl; }  // 隐藏
    void fun(double a) { cout << "class B fun with double" << endl; }  // 隐藏
    void fun(int a, float b) { cout << "class B fun with int and float" << endl; }  // 隐藏
    virtual void fun(float a, int b) { cout << "class B virtual fun with float and int" << endl; }  // 隐藏
    virtual void fun(int a, float b, char c) const override { cout << "class B override virtual fun with int and float const" << endl; }  // 重写
};

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    string str("string");
    A* a = new A;
    a->fun(1);
    a->fun(1.009);
    a->fun(1, 1.09);
    a->fun(1.09, 1);
    a->fun(1, 1.09, 'a');
    a->fun(str);

    B* b = new B;
    b->fun(1);
    b->fun(1.009);
    b->fun(1, 1.09);
    b->fun(1.09, 1);
    b->fun(1, 1.09, 'a');
    // b->fun(str); // 此时入参为string的A中的函数已经被隐藏了，且此时指针类型是B，B中找不到入参为string类型的重载，因此会报错
    b->A::fun(str);

    A* c = new B;
    c->fun(1);
    c->fun(1.009);
    c->fun(1, 1.09);
    c->fun(1.09, 1);
    c->fun(1, 1.09, 'a');
    c->fun(str);
    return 0;
}