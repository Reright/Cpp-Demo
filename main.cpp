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

    A ex1;
    ex1.funA(); // class A

    B ex2;
    ex2.funA(); // class A
    ex2.funB(); // class B

    C ex3;
    // ex3.funB(); // error: 'B' is not an accessible base of 'C'.
    ex3.funA();
    return 0;
}