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

    std::vector<MyTest> vect;
    vect.reserve(2); //预先分配内存
    cout << "\n ------ push_back --------"<< endl;
    vect.push_back(MyTest(1, 20));
    cout << "\n ------ emplace_back --------"<< endl;
    vect.emplace_back(1, 20);  // 这是emplace_back的标准用法，可以提升插入效率
    cout << "\n -------- finish -------- "<< endl;
    return 0;
}