#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

void ShowBasic()
{
    int i = 0;
    int &j = i;  // 左值引用，j相当于i的别名
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
    m = a;  // 右值可以赋给右值
    cout << "m = " << m << " a = "  << a << endl;
}