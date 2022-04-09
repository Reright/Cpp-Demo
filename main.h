#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <numbers>
#include <numeric>
#include <time.h>
#include <type_traits>

using namespace std;

void ShowBasic()
{
    int i = 0;
    int &j = i;  // 左值引用，j相当于i的别名；int& 是对左值绑定
    j = 5;
    cout << "i = " << i << endl;
    ((i > 0) ? i : j) = 1; // 正确，右值也可以出现在赋值表达式的左边？？？
    cout << "i = " << i << endl;
    // int &k = 10;
    const int &l = 10; // 正确，这是特殊情况，左值引用常量;const变量对于编译器来说就是常量，所以用常量来赋值是可行的。
    cout << "l = " << l << endl;

    // int &&m = i; // 错误，无法将右值引用绑定到左值
    int &&m = i + 5; // 正确，右值引用,跟上面比较，右边是一个表达式，也是右值，所以这里是右值赋给右值
    cout << "m = " << m << endl;
    m += 4;
    cout << "m = " << m << " i = "  << i << endl;
    int n = m;  // m是右值，n是左值，所以右值可以赋给左值。
    cout << "n = " << n << endl;

    // int &&n = m;  // 错误，无法将右值引用绑定到左值
    int &&a = 1;
    const int &b = 1;
    m = a;  // 右值引用可以赋给右值引用
    cout << "m = " << m << " a = "  << a << endl;
}

int g_constructCount=0;
int g_copyConstructCount=0;
int g_destructCount=0;
struct A
{
    A()
    {
        cout<<"construct: "<<++g_constructCount<<endl;    
    }
    
    A(const A& a)
    {
        cout<<"copy construct: "<<++g_copyConstructCount <<endl;
    }
    A(A&& a)
    {
        cout<<"&& move construct: " <<endl;
    }
    ~A()
    {
        // 在这里打印出this指针的地址真是绝了，不愧是我---by dzw-2022.04.07
        // cout<<"destruct: "<<++g_destructCount<< " this is " << this << endl;
    }
};

A GetA()
{
    cout << "Enter GetA()\n"; 
    // A a;
    // cout << "A in GetA() is " << &a << endl;
    return A();
    // cout << "Leave GetA()\n";
}

template<typename T>
    void f(T&& t){
        // 用T&& 作为参数类型，既可以是左值也可以是右值，提高了灵活性
        // 如果写成T&,那就只能是左值，那么f(10)的用法就不合法了；
        // 但是写成f(T t)还是可以的。
    }

int g_times = 0;
void TestRefPass(A& a)  // 左值引用传递,所以之前说的“引用传递”具体来说就是左值引用传递。
{
    cout << ++g_times << " Enter TestLeftRefPass()\n" << endl;
    return;
}

void TestRefPass(A&& a)  // 右值引用传递
{
    cout << ++g_times << " Enter TestRightRefPass()\n" << endl;
    return;
}

void TestValuePass(A a)  // 值传递
{
    // 隐形代码：A tmp(a);
    cout << ++g_times << " Enter TestValuePass()\n" << endl;
    return;
}

class B
{
public:
    B():m_ptr(new int(0)){cout << "construct" << endl;}
    B(const B& a):m_ptr(new int(*a.m_ptr)) //深拷贝的拷贝构造函数
    {
        cout << "copy construct" << endl;
    }
    // B(B&& a) :m_ptr(a.m_ptr)
    // {
    //     a.m_ptr = nullptr;
    //     cout << "move construct" << endl;
    // }
    ~B(){ delete m_ptr;}
private:
    int* m_ptr;
};

B GetB(int b)
{
    cout << "Enter GetB()\n";
    B f;  // 效果上相当于return B()
    return f;
    // return B(); B()是要销毁的，所以这里要拷贝一个临时值，也就是出去之后等号右边的临时值，所以要消耗一次拷贝构造
}

void processValue(int& a){ cout << "lvalue" << endl; }
void processValue(int&& a){ cout << "rvalue" << endl; }

/*
template <typename T>
void forwardValue(T& val)
{
    cout << "T& val" << endl;
    processValue(val); //按照这种定义方式，右值参数会变成左值 
}

template <typename T>
void forwardValue(const T& val)
{
    cout << "const T& val" << endl;
    processValue(val); //按照这种定义方式，入参都变成常量左值引用了 
}
*/

template <typename T>
void forwardValue(T&& val)  // 参数推断使得入参可以是左值或右值
{
    cout << "T&& val" << endl;
    processValue(std::forward<T>(val)); //照参数本来的类型进行转发。
}

void Testdelcl()
{
    int i = 0;
    forwardValue(i);  //传入左值 
    forwardValue(0);  //传入右值 
}