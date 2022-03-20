#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// static作用于全局变量和函数，作用域仅限本文件，在外部即使使用extern也不能访问
static char* stchar = "This is static string.";


// static 作用于局部变量，改变了局部变量的生存周期，使得该变量存在于定义后直到程序运行结束的这段时间
int fun1()
{
    // 1. var 是局部变量，作用域只是该代码块
    // 2. var 的生存周期直到程序运行结束，因此只在第一次进入这个函数的时初始化
    static int var = 1;
    var += 1;
    return var;
}

int fun2()
{
    static int count = 10; //在第一次进入这个函数的时候，count被初始化为10！并接着自减1，以后每次进入该函数，count
    return count--; //就不会被再次初始化了，仅进行自减1的操作；在static发明前，要达到同样的功能，则只能使用全局变量：    
 
}

// 实测：这里如果变量名是count，下面main是找不到这个全局变量的，编译器无法确定是哪个count。
// 另外，全局变量默认初始值为0
int g_count;


class A
{
private:
    int var;
    static int s_var; // 静态成员变量
public:
    static int p_s_var; // 静态成员变量
    void show()
    {
        cout << s_var++ << endl;
    }
    static void s_show()
    {
        cout << s_var << endl;
		// cout << var << endl; // 静态成员函数不能调用非静态成员变量。无法使用 this.var
        // show();  // 静态成员函数不能调用非静态成员函数。无法使用 this.show()
    }
};

// 静态成员变量的初始化格式：
// <数据类型><类名>::<静态数据成员名>=<值>
// 不能带public/private;不能带static;必须带数据类型(看起来像声明一个变量...)
int A::s_var = 1;  // 静态成员变量在类外进行初始化赋值，默认初始化为 0
// int A::s_var = 3;  // 不可以重复初始化
int A::p_s_var = 3;

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    for (int i = 0; i < 10; i++) {
        cout << fun1() << " " ;
    }
    
    printf("\nglobal    local static\n");
     for(; g_count <= 10; ++g_count)
            printf("%d\t\t%d\n", g_count, fun2());
    cout << endl << endl << "Demo Ends!" << endl;

    static char str[10]; // 默认初始化为0
    printf("integer: %d; string: (begin)%s(end)\n", g_count, str);
    strcpy(str,"Lessthan1");
    printf("integer: %d; string: (begin)%s(end)\n", g_count, str);

    A ex;
    ex.show();
    cout << A::p_s_var << endl;    // correct: 'A::s_var'是静态成员，且是public类型的，故可以在外部访问。
    // cout << A::s_var << endl;    // error: 'A::s_var'是静态成员，但它是private类型的，故不可在外部访问。
    A::s_show();  // 静态成员函数的访问方式：className::method().
    return 0;
}