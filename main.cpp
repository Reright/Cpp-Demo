#include "main.h"

using namespace std;

void TestIsConst()
{
    std::cout << std::boolalpha;
    cout << "================Test std::is_const================\n";
	std::cout << "is_const:" << std::endl;
	std::cout << "int: " << std::is_const<int>::value << std::endl;
	std::cout << "const int: " << std::is_const_v<const int> << std::endl;  // C++17支持is_const_v
	std::cout << "const int&: " << std::is_const<const int&>::value << std::endl;   // false
	std::cout << "const int* " << std::is_const<const int*>::value << std::endl;    // false
	std::cout << "int * const:" << std::is_const<int* const>::value << std::endl;   // true
    cout << endl;
}

int main(int argc, char**  argv)
{
	TestIsConst();
    vector<int> vec = {0, 1, 2, 3, 4, 5};
    vector<int>&& tmp = dmove(vec);
    decltype(10) a = dmove(10);

    int n = 0;
    int& m = n;
    int&& l = 1;


    cout << "================模板特化示例================\n";

    char arr1[] = "hello";
    char arr2[] = "abc";
    cout << compare(123, 123) << endl;
    cout << compare(arr1, arr2) << endl;


    //举例如下,下列定义的a、b、c三个变量都是int类型
    int i;  
    remove_refrence<decltype(42)>::type c;              //使用原版本，
    remove_refrence<decltype(i)>::type  d;              //左值引用特例版本
    remove_refrence<decltype(std::move(i))>::type  e;   //右值引用特例版本 

    /*
    int var1, var2;
    cin >> var1 >> var2;
    cout << add_fun(var1, var2);

    double var3, var4;
    cin >> var3 >> var4;
    cout << add_fun(var3, var4);
    */
    cout << add_fun(7, 8) << endl;  // 隐式实例化
    cout << add_fun<double>(2.1, 5) << endl;      // 显式实例化,5会被强制转换成double类型
    double x = 5;
    double y = 6.7;
    Swap<double>(x, y);  // int可以转换成double, 但是int不能转换成double&
    cout << "x = " << x << ", y = " << y << endl;
    try {
        Base * pba = new Derived;
        Base * pbb = new Base;
        Derived * pd;

        pd = dynamic_cast<Derived*>(pba);
        if (pd==0) cout << "Null pointer on first type-cast.\n";

        pd = dynamic_cast<Derived*>(pbb);
        if (pd==0) cout << "Null pointer on second type-cast.\n";

    } catch (exception& e) {cout << "Exception: " << e.what();}

    // Base* base = new Derived;
    int cst = 9;
    int *pa = &cst;
    Base* base = reinterpret_cast<Base*>(pa);  // 可以转，但不保证有效性和正确性
	// base->dummy();  // 会报错

    const char * cstr = "sample text";
    char* str = const_cast<char*>(cstr);
    cout << str << endl;
    str = const_cast<char*>("another sample");
    cout << str << endl;
    return 0;
}