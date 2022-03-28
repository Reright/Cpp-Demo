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
    A(const string& a):dscrp(a)
    {
        cout << "调用 A 构造函数 : " << dscrp << endl;
    }
    ~A()
    {
        cout << "调用 A 析构函数 : " << dscrp << endl;
    }
private:
    string dscrp;
};

void GetA()
{
    cout << "进入 GetA 函数执行" << endl;
    static A a("局部静态变量");
}