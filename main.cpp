#include "main.h"

using namespace std;

/*
** 右值引用的意义:
** 为临时变量续命，也就是为右值续命，因为右值在表达式
** 结束后就消亡了，如果想继续使用右值，那就会动用昂贵
** 的拷贝构造函数。
*/

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl;
    cout << "========左值右值========" << endl;
    int i = 0;
    int &j = i;  // 左值引用，j相当于i的别名
    j = 5;
    cout << "i = " << i << endl;
    ((i > 0) ? i : j) = 1; // 正确，右值也可以出现在赋值表达式的左边？？？
    cout << "i = " << i << endl;
    // int &k = 10;
    const int &l = 10; // 正确，这是特殊情况，左值引用常量;const变量对于编译器来说就是常量，所以用常量来赋值是可行的。
    cout << "l = " << l << endl;

    int &&m = i + 5; // 正确，右值引用
    cout << "m = " << m << endl;
    m += 4;
    cout << "m = " << m << " i = "  << i << endl;
    int n = m;
    cout << "n = " << n << endl;

    // int &&n = m;  // 错误，无法将右值引用绑定到左值
    int &&a = 1;
    const int &b = 1;

    return 0;
}