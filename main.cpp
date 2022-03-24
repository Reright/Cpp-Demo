#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class A {
public:
    A(int a):ca(a)//sca(a)//sa(a)
    {
        na = a;
        // ca = a;
        // sa = a;
        // sca = a;
    }

private:
    int na = 3;  // 不能在类外部初始化；可以在初始化列表中初始化；可以在构造函数中初始化；接受声明时的默认值
    const int ca = 3;  // 不能在类外部初始化；可以在初始化列表中初始化；不能在构造函数中初始化；接受声明时的默认值
    static int sa; //= 3; // 可以在类外部初始化；不能在初始化列表中初始化；不能在构造函数中初始化；不接受声明时的默认值
    static const int sca = 3; //可以在类外部初始化(在外部初始化时必须加上const)；不能在初始化列表中初始化；不能在构造函数中初始化，接受声明时的默认值
};

int A::sa = 4;
// const int A::sca = 5;

void printOS(){
    cout << "your Operating System :";
#ifdef _WIN32
    cout << " Windows!" << endl;
#elif __linux__
    cout << " Linux!" << endl;
#elif __APPLE__
    cout << " MAC!" << endl;
#else
    cout << " others" << endl;
#endif
}

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    A* pa1 = new A(2);
    printOS();
    return 0;
}