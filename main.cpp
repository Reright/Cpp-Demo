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

    int&& x = 3;
    process_value(x);  // LValue, 可见右值引用被视为一个左值
    return 0;
}