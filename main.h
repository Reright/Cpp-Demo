#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Student
{
    public:
    string name;
    int score;
    Student(string _name, int _score):name(_name), score(_score)
    {

    };
    ~Student()
    {

    };
};


class A {
private:
    int a;
public:
	virtual void set_a(int x) { this->a = x; }
	void put_a() { cout << this->a << endl; }
    void f() { cout << "non_const" << endl; }

    void f() const { cout << "const" << endl; }
};

class B :public A {
private:
	int b;
public:
	void set_b() { b = 10; }
	void set_a(int x) { this->b = x; }
	virtual void put_b() { cout << this->b << endl; }
};

class Base {
public:
    virtual void fun() { cout << "virtual void Base::fun()" << endl; }

    virtual void fun1() const { cout << "virtual void Base::fun1() const" << endl; }

    virtual void fun2() final { cout << "virtual void Base::fun2() final" << endl; }

    void fun3() { cout << "void Base::fun3()" << endl; }  // 普通函数不存在重写的关系

    virtual void fun4() = 0;
};

void Base::fun4()  // 纯虚函数是可以定义的，但它不会被派生类继承
{
    cout << "virtual void Base::fun4() = 0" << endl;
}

class Derive final : public Base {  // derive是最后一个继承类，其他类不能再继承Derive
public:
    void fun() override { cout << "void Derive::fun() override" << endl; }
    
    virtual void D_fun1() { cout << "virtual void Derive::D_fun1()" << endl; }

    virtual void D_fun2() { cout << "virtual void Derive::D_fun2()" << endl; }

    void fun1() const override { cout << "void Derive::fun1() const override" << endl; }

    void D_fun3() { cout << "void Derive::D_fun3()" << endl; }

    void fun3() { cout << "void Derive::fun3()" << endl; }  // 原则上不建议重新定义父类中的非虚函数(即隐藏)

    void fun4() override { cout << "void Derive::fun4() override" << endl; }
};