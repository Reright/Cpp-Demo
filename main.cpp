#include "main.h"

using namespace std;

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    // Derive* der = new Derive(1, 2);
    Derive* der = Derive::create(1, 2);
    // Base* base = new Base();
    // der->fun();
    der->funD();
    Base* base = new Base(0);
    // base->fun();  // fun是Base类型的private函数
    return 0;
}