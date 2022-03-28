#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class A
{
public:
    A()
    {
        cout << "调用全局变量 A 构造函数" << endl;
    }
    A(int a):m_a(a)
    {
        cout << "调用 A 构造函数, 静态属性: " << m_a << endl;
    }
    ~A()
    {
        cout << "调用 A 析构函数, 静态属性: " << m_a << endl;
    }
private:
    int m_a;
};

void GetA()
{
    cout << "进入 GetA 函数执行" << endl;
    static A a(1);
}