#include "main.h"

using namespace std;

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl;
    vector<int> arr;
    std::shared_ptr<int> fix1(new int);
    // shared_ptr是个类， 所以不能写成std::shared_ptr<int> p = new int(1); 
    std::shared_ptr<Student> li(new Student("LiHua", 96));
    // 把(new Student("LiHua", 96))这一指针当作li的入参，shared_ptr是个模板类，Student是模板。
    std::shared_ptr<Student> wang = std::make_shared<Student>("Wang", 98);
    std::cout << li->name << " " << li->score << std::endl;
    std::cout << wang->name << " " << wang->score << std::endl;

    shared_ptr<double> pd;  // 这时是一个空指针，0x0
    cout << hex << "0x" << pd << endl;
    double* p_reg = new double;
    cout << hex << "0x" << p_reg << " " << *p_reg << endl;
    // pd = p_reg; 这样是错误的，普通指针不能直接赋值给智能指针，但可以作为智能指针的入参来初始化它，如：
    pd = shared_ptr<double>(p_reg);
    cout << hex << "0x" << pd << " " << *p_reg << endl;
    // 把智能指针赋值给普通指针也是不可以的,虽然c++pp上说可以，但实际编译是不通过的：
    // double* p_new = pd;
    std::vector<int>* vptr = new std::vector<int>{1, 2, 3, 4, 5};
    vptr->push_back(7);
    for(int i = 0; i < vptr->size(); i++) {
        std::cout << " It's back is " << vptr->back() << std::endl; 
        break;
    }
    shared_ptr<double> dptr(new double(7.009));
    cout << "double is " << *dptr << endl;

    unique_ptr<string> str(new string("This is unique_ptr test."));
    cout << *str << endl;

    cout << endl << endl << "A B class test " << endl;
    A objA, *pA;
	B objB;
	pA = &objB;
	pA->set_a(10);
    cout << "pA->put(a)" << endl;
    pA->put_a();
	// pA->put_b();//会报错
    objB.set_b();
    cout << "objB.put_b()" << endl;
    objB.put_b();
    // pA->set_b(); 这是非虚函数，看指针类型，A没有set_b()函数，所以报错

    cout << endl << endl << "========Virtual Function========" << endl;
    // Derive* der_base = new Base();  不允许
    // Base* base_base = new Base(); Base中有纯虚函数，无法直接实例化
    Derive* der = new Derive();
    Base* base = new Derive();
    cout << "Derive method" << endl;
    der->fun();
    der->fun1();
    der->fun2();
    der->fun3();
    der->fun4();
    der->D_fun1();
    der->D_fun2();
    der->D_fun3();

    cout << endl << endl;
    cout << "Base method" << endl;
    base->fun();
    base->fun1();
    base->fun2();
    base->fun3();
    base->fun4();

    delete der;  // 显式释放指针才能在程序结束前调用析构函数
    delete base;

    cout << endl << endl << "========Const========" << endl;
    A a1;
    const A &b1 = a1;
    b1.f();  // const
    const A *c1 = &a1;
    c1->f();  // const
    const A *f = c1;
    f->f();  // const
    A* const d1 = &a1;
    d1->f();  // non const
    A* const e = d1;
    e->f();  // non const
    cout << endl << endl << "Demo ends" << endl;

    cout << endl << endl << "========Virtual Function Table========" << endl;
    A pa1,pa2;
    B pb1, pb2;
    int * pVfptr = (int*)(&pa1);
    printf("pa1 的__vfptr = %x\n",(*pVfptr));

    pVfptr = (int*)(&pa2);
    printf("pa2 的__vfptr = %x\n",(*pVfptr));

    pVfptr = (int*)(&pb1);
    printf("pb1 的__vfptr = %x\n",(*pVfptr));

    pVfptr = (int*)(&pb2);
    printf("pb2 的__vfptr = %x\n",(*pVfptr));
    return 0;
}