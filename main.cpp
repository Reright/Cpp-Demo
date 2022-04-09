#include "main.h"

using namespace std;

/*
rvalue: read value,可提供读值的数据
lvalue: locator value，存储在内存中，可寻址的数据
** 右值引用的意义:
** 为临时变量续命，也就是为右值续命，因为右值在表达式
** 结束后就消亡了，如果想继续使用右值，那就会动用昂贵
** 的拷贝构造函数。
** 右值引用用来支持转移语义
** 转移语义可以将资源(堆，系统对象等)从一个对象转移到
** 另一个对象，这样能够减少不必要的临时对象的创建、拷
** 贝以及销毁，能够大幅度提高C++应用程序的性能。临时
** 对象的维护(创建和销毁)对性能有严重影响。
** =========================================
** 右值引用本身是一个左值,见下面的实验。
** 左值 = 左值，可以, 天经地义
** 左值 = 右值引用，可以, 如下文中"int n = m"
** 右值引用 = 右值引用，可以, 如下文中所述的“右值引用可以赋给右值引用”，表达式作为右值也可以赋给右值引用
** 右值引用 = 左值，不可以，如下文中所述的“无法将右值引用绑定到左值”
*/

void process_value(int& i)
{
    cout << "LValue Processed: " << i << endl;
}

void process_value(int&& i)
{
    cout << "RValue Processed: " << i << endl;
}

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl;
    cout << "========左值右值========" << endl;
    ShowBasic();

    int a = 0;
    process_value(a);  // LValue
    process_value(1);  // RValue
    process_value((a != 0) ? 1 : -1);  // RValue
    process_value(a++);  // RValue
    process_value(++a);  // LValue

    int&& x = 3;
    process_value(x);  // LValue, 可见具名的右值引用被视为一个左值

    cout << "\nA a1 = GetA();" << endl;
    A a1 = GetA();
    cout << "a1 in main is " << &a1 << endl;
    g_constructCount=0;
    g_copyConstructCount=0;
    g_destructCount=0;
    cout << "\nA&& a2 = GetA();" << endl;
    A&& a2 = GetA();  // 少一次拷贝和析构
    cout << "a2 in main is " << &a2 << endl;
    g_constructCount=0;
    g_copyConstructCount=0;
    g_destructCount=0;
    // cout << "\n It ends" << endl;
    cout << "\nconst A& a3 = GetA();" << endl;
    const A& a3 = GetA();  // 常量左值引用是“万能”引用类型
    // A& a4 = GetA();  // 普通左值引用只能接受左值
    cout << "a3 in main is " << &a3 << endl;
    int var1 = 1;
    cout << "Address of var1 is " << &var1 << endl << endl << endl;
    f(10);  // T&& 是右值
    f(a);   // T&& 是左值
    int&& yvar = 1;  // 右值引用只能绑定到右值上
    // int&& var2 = var1;  // 右值引用不能绑定到左值上
    int& j = var1;  // 左值引用可以绑定到左值上
    j = yvar;  // 这里yvar本身是一个左值，见上面:具名的右值引用是一个左值
    // int& m = 1;  // 普通左值引用不能绑定到右值上
    const int& m = 1;  // 常量左值引用是“万能”引用类型

    cout << "================Test reference pass================" << endl;
    TestRefPass(a1);   // 匹配左值引用， 啥也不干
    TestRefPass(A());  // 匹配右值引用，构造一次就结束
    TestValuePass(a1); // 匹配值传递，要拷贝一次，但此时的a1是左值，所以匹配拷贝构造函数
    TestValuePass(A());// 匹配值传递，要拷贝一次，但此时A()是右值，所以匹配移动构造函数
    cout << "================Class B Test================" << endl;
    B b = GetB(false);
    GetB(false);
    cout << "================std::move Test================" << endl;
    vector<int> vec = {0, 1, 2, 3, 4, 5};
    // vector<int> v = std::move(vec);  // 资源所有权转移，move之后vec就为空了
    // vector<int> v(vec);          // 用vec初始化v，vec仍然存在
    vector<int> v = vec;          // 用vec初始化v，vec仍然存在
    for_each(v.begin(), v.end(), [](auto c){ cout << c << " "; });
    cout << endl;
    v[2] = 9;
    for_each(v.begin(), v.end(), [](auto c){ cout << c << " "; });
    cout << "\nvec after move: " <<endl;
    for_each(vec.begin(), vec.end(), [](auto c){ cout << c << " "; });

    cout << "\n================完美转发================" << endl;
    Testdelcl();
    return 0;
}