#include "main.h"

using namespace std;

/*
** 拷贝语义--拷贝--拷贝构造函数--拷贝赋值操作(“=”重载):造成无意义的资源申请和释放
** 转移语义--剪切--转移构造函数--转移赋值操作(“=”重载):直接使用临时对象已申请的资源
** 默认构造函数
** 拷贝构造函数
** 移动构造函数
** 拷贝赋值
** 移动赋值
** 赋值构造函数
** 右值引用用来支持转移语义
** 转移语义可以将资源(堆，系统对象等)从一个对象转移到
** 另一个对象，这样能够减少不必要的临时对象的创建、拷
** 贝以及销毁，能够大幅度提高C++应用程序的性能。临时
** 对象的维护(创建和销毁)对性能有严重影响。
*/

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    MyString* a;
    a = new MyString("HelloWorld!");
    delete a;
    // 上面的过程没有输出任何打印，只是执行了第二个构造函数而已。

    MyString b;
    // b = MyString("Hello");  // 调用了拷贝赋值操作;有了转移赋值操作后，调用转移赋值操作
    std::vector<MyString> vec;
    // vec.push_back(MyString("push1"));  // 调用了拷贝构造函数;有了转移构造函数后，调用转移构造函数
    vec.emplace_back("emplace");

    deque<MyString> queue;
    list<MyString> list;
    queue.emplace_back("queue1");

    cout << "\n ************************** Test01 ******************** "<< endl;
    std::vector<MyTest> vect;
    vect.reserve(2); //预先分配内存
    cout << "\n ---- push_back ----"<< endl;
    vect.push_back(MyTest(1, 20));
    cout << "\n ---- emplace_back ----"<< endl;
    vect.emplace_back(1, 20);  // 这是emplace_back的标准用法，可以提升插入效率
    cout << "\n ---- finish ---- "<< endl;

    cout << "\n ************************** Test02 ************************** "<< endl;
    std::vector<President> elections;  
    std::cout << "emplace_back:\n";  
    elections.emplace_back("Nelson Mandela", "South Africa", 1994); // 直接传入类的构造参数

    std::vector<President> reElections;  
    std::cout << "\npush_back:\n";  
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));  // 必须传入一个临时对象  

    std::cout << "\nContents:\n";  
    for (President const& president: elections) {  
       std::cout << president.name << " was elected president of "  
            << president.country << " in " << president.year << ".\n";  
    }  
    for (President const& president: reElections) {  
        std::cout << president.name << " was re-elected president of "  
            << president.country << " in " << president.year << ".\n";  
    }

    cout << "\n ************************** Test03 ************************** "<< endl;
    string tmp = "Nameca";
    A ca(0, tmp.c_str());  // c_str()返回的是一个const char*
    // 禁用了拷贝构造函数后，一下两种用法都被禁止了
    // A cb(ca);  
    // A cb = ca;
    ca.PrintOut();
    // A ta;  已经提供了一个构造函数，默认的无参构造就无法调用了
    // cb.PrintOut();

    // const B sb;  // programmar定义了任意一种构造函数后，编译器就不再提供默认构造函数，因此不能这样声明
    const B sb(2, "Namesb");
    sb.PrintOut();

    Test1 ex1;
    cout << endl;
    Test2 ex2;

    cout << "\n ************************** Test04 ************************** "<< endl;
    cout << "Size of class EmptyClass is " << sizeof(EmptyClass) << endl;
    EmptyClass emptycl;
    cout << "Size of EmptyClass Object is " << sizeof(emptycl) << endl;
    return 0;
}