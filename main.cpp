#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;


const int * mallocA()
{   //const data,non-const pointer
    int *a=new int(2);
    return a;
}

int* const mallocB()
{   //non-const data,const pointer
    int *a=new int(2);
    return a;
}

const int* const mallocC()
{   //const data,const pointer
    int *a=new int(2);
    return a;
}

int const* const mallocD()
{   //const data,const pointer
    int *a=new int(2);
    return a;
}

const int* const mallocE()
{   //const data,non-const pointer

    const int* a = new int(2);  // 返回值类型和函数类型必须匹配。
    int* b = new int(2);
    int* const c = new int(2);
    // int* a = new int(2);
    // return a;
    // return b;
    return c;
}

class Point {
public:
    Point(int _x, int _z):x(_x), z(_z)  //可以在初始化列表中初始化const成员变量 
    {
        // z = 10; 不可以在构造函数中初始化const成员变量
    }
    
    void testConstFunction(int _x) const
    {
        // x = _x;   const修饰的成员函数无法修改非mutable修饰的成员变量
        // modify_x(x);  const修饰的成员函数无法调用非const成员函数
        y = _x;
    }

    void modify_x(int _x)
    {
        x = _x;
    }
    const int Get_z()
    {
        cout << "z: " << z << endl;
        return z;
    }
private:
    int x;
    mutable int y;
    const int z;  // 可以在声明时初始化，提供一个默认初始化值，但可以被初始化列表覆盖。
};

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;

    cout << "======左定值，右定向======" << endl;
    int a0 = 2;
    int a1=3;   ///non-const data
    const int a2=a1;    ///const data 
    int * a3 = &a1;   ///non-const data,non-const pointer
    *a3 = 4;
    const int * a4 = &a1;   ///const data,non-const pointer
    int * const a5 = &a1;   ///non-const data,const pointer
    int const * const a6 = &a1;   ///const data,const pointer
    const int * const a7 = &a1;   ///const data,const pointer
    int* a8 = (int*)&a2; // 强制转换const类型后并不能通过a8改变a2的值
    *a8 = 8;
    a1 = 4;
    // &a1 = &a0;  a1并非指针变量， 其地址是不可变
    // a2 = 5;  a2的值不可改
    // &a2 = &a0; a2的地址也不可改
    *a3 = 6;
    // *a4 = 7;  // 不能通过指针修改指向的值
    a4 = &a0;  // 可以修改指向
    // *a5 = 8;
    // *a6 = 9;
    // *a7 = 10;
    cout <<
    "a1: " << a1 << endl << 
    "a2: " << a2 << endl << 
    "a3: " << *a3 << endl <<
    "a4: " << *a4 << endl <<
    "a5: " << *a5 << endl <<
    "a6: " << *a6 << endl <<
    "a7: " << *a7 << endl <<
    "a8: " << *a8 << endl;

    cout << "======通过不同指针修改值======" << endl;
    int a = 8;
    int* const p1 = &a;
    *p1 = 9; //it’s right
    cout << 
    "int a: " << a << endl <<
    "*p1: " << *p1 << endl;

    const int b = 8;  // 可以认为，编译器把b当成了一个常量，其值就是固定的8
    int* p2 = (int*)&b; // 经过强制类型转换之后， b和p2的指针地址应该是不一致的？
    // int* p2 = &b; const属性不一致，不能直接赋值。
    *p2 = 9;
    cout << 
    "const int b: " << b << endl <<  // 尽管p2已经将值改成了9，但编译器仍把b当成是8.
    "int* p2: " << *p2 << endl <<
    "&b: " << &b << endl <<
    "p2: " << p2 << endl;

    // int  b = 7;
    // p = &b; //it’s wrong


    cout << "======Const 修饰返回值======" << endl;
    const int* A = mallocA();
    A = &a0;
    // *A = 8;
    // int* A1 = mallocA();  //const data也必须由const data型的指针接收。
    int* const B = mallocB();
    int* B1 = mallocB();
    const int* const C = mallocC();
    const int* const D = mallocD();  //说明int const* 和 const int*等价？
    const int* const E = mallocE();
    cout << *A << " " << *B << " " << *C << " " << *D << endl;
    cout << hex << A << endl << B << endl << C << endl << D << endl;
    cout << hex << &A << endl << &B << endl << &C << endl << &D << endl;

    cout << "======Const 引用======" << endl;
    int i = 42;
    int &r1 = i;
    const int &r2 = i;
    r1 = 0;
    cout <<
    "i: " << i << endl <<
    "r1: " << r1 << endl <<
    "r2: " << r1 << endl;
    // r2 = 1;  const引用不能修改它所绑定的对象

    const int ci = 1024;
    // int &r3 = ci;  不能将非常量引用指向一个常量对象
    
    cout << "======Const成员变量======" << endl;
    Point* cp = new Point(3,7);
    cp->Get_z();
    return 0;
}