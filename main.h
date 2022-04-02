#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <deque>
#include <list>

using namespace std;

class MyString {
private:
    char* _data;
    size_t _len;
    void _init_data(const char* s)
    {
        _data = new char[_len + 1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }
public:
    MyString()
    {
        _data = nullptr;
        _len = 0;
    }

    MyString(const char* p)
    {
        _len = strlen(p);
        _init_data(p);
    }

    MyString(const MyString& str)  // 拷贝构造函数
    {
        _len = str._len;  // 为什么能访问到private变量？
        _init_data(str._data);
        cout << "Copy Constructor is Called! Source: " << str._data << endl;
    }

    MyString(const MyString&& str)  // 转移构造函数
    {
        _len = str._len;
        _init_data(str._data);
        // str._len = 0;        // 错误，str并非可修改的左值
        // str._data = nullptr; // 同上
        // free(str._data);提示"pointer being freed was not allocated"，说明str没在内存中.
        cout << "Move Constructor is Called! Source: " << str._data << endl;
    }

    MyString& operator=(const MyString& str)  // 拷贝赋值操作
    {
        if (this != &str) {  // 从这里能看出，this就是指向该对象的指针，也就是对象的地址
            _len = str._len;
            _init_data(str._data);
        }
        cout << "Copy Assignment is Called! Source: " << str._data << endl;
        return *this;
    }

    MyString& operator=(const MyString&& str)  // 转移赋值操作
    {
        
        _len = str._len;
        _init_data(str._data);
        cout << "Move Assignment is Called! Source: " << str._data << endl;
        return *this;
    }

    virtual ~MyString()
    {
        if (_data)
            free(_data);
    }
};


class MyTest {

public:
    //普通构造
    MyTest(int id,int age):m_id(id),m_age(age)
    {
        cout << "ceate MyTest class..."<< this << endl;
    }

    //拷贝构造
    MyTest(const MyTest &t):m_id(t.m_id),m_age(t.m_age)
    {
        cout << "copy construct called..."<< this << endl;
    }
    //移动构造
    MyTest(const MyTest &&t)
    {
        m_id = std::move(t.m_id);
        m_age = std::move(t.m_age);
        cout << "move contruct called.."<< this << endl;
    }
    //析构
    virtual ~MyTest()
    {
        cout << "destory MyTest class..."<< this << endl;
    }
private:
    int m_id; //id成员
    int m_age;//age成员
};


struct President  
{  
    std::string name;  
    std::string country;  
    int year;  

    President(std::string p_name, std::string p_country, int p_year)  
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)  
    {  
        std::cout << "I am being constructed.\n";  
    }
    President(const President& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "I am being copy constructed.\n";
    }
    President(President&& other)  
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)  
    {  
        std::cout << "I am being moved.\n";  
    }  
    President& operator=(const President& other);  
};  

class A {
public:
    A(int a, const char* str) : m_a(a), m_str(str)
    {
        cout << "Newly-Defined Constructor! " << endl;
    }
    A() = delete;
    A(const A& a) = delete;

    void PrintOut()
    {
        cout << "a is " << m_a << " , str is " << m_str << endl;
    }
private:
    int m_a;
    const char* m_str;
};

class B {
public:
    B(int id, const char* name)
    {
        m_id = id;
        m_name = name;
    }

    virtual void PrintOut() const
    {
        cout << "ID is " << m_id << " Name is " << m_name << endl;
    }
private:
    int m_id = 1;
    const char* m_name = "Noname";
};

class A2 {
private:
    int val;
public:
    A2()
    {
        cout << "A2()" << endl;
    }
    A2(int tmp)
    {
        val = tmp;
        cout << "A2(int " << val << ")" << endl;
    }
    A2(const A2& tmp)
    {
        cout << "A2(const A2& tmp)" << endl;
    }

    A2& operator = (const A2& tmp)
    {
        cout << "A2& operator = (const A2& tmp)" << endl;
        return *this;  //这里是return *this,想想为什么？
    }

    void fun(A2 tmp)
    {

    }
};

class Test1 {
private:
    A2 ex;

public:
    Test1() : ex(1) // 成员列表初始化方式
    {
        cout << "Test 1" << endl << endl;
    }
};

class Test2 {
private:
    A2 ex;

public:
    Test2() // 函数体中赋值的方式
    // 这里没有通过参数列表初始化的方式，所以ex会先自动调用默认构造函数， 因此会先打印“A2()”
    {
        ex = A2(2);
        cout << "Test 2" << endl << endl;
        // 然后等号右边的临时变量A2(2)通过构造函数构造出来，打印"A2(int a)"
        // 最后把临时变量赋值给ex，调用了赋值操作符，打印"operator"
    }
};

class Test3 {
private:
    A2 ex;

public:
    Test3(const A2& tmp):ex(tmp)
    {
        ex.fun(tmp);
        cout << "Test 3" << endl;
    }
};

class A3 {
public:
    A3(int a, int b):m_b(b), m_a(a)  // 编译时会告警，m_b会在m_a后面初始化，按照声明的顺序
    {
        // m_a = a;
        // m_b = b;
        cout << "m_a: " << m_a << " m_b: " << m_b << endl;
    }
private:
    int m_a;
    int m_b;
};

class Test4 {
private:
    A2 a2;
    A3 a3;
public:
    // 这里即便不利用初始化列表来初始化a3，也会调用默认构造函数先初始化一把
    Test4(int a, int b):a2(a), a3(a, b) 
    {
        cout << "Test 4" << endl;
        // a2 = A2(a);
        // 如果不在初始化列表中给a2传参初始化，则会调用默认构造函数；
        // 而A2已经提供了一个构造函数，编译器不会再提供默认构造函数，因此会报错。
    }
};

/*
class EmptyClass
{}; 该空类的等价写法如下：
*/
class EmptyClass
{
public:
    EmptyClass(){};                                       // 缺省构造函数
    EmptyClass(const EmptyClass &tmp){};                  // 拷贝构造函数
    ~EmptyClass(){};                                      // 析构函数
    EmptyClass &operator=(const EmptyClass &tmp)          // 赋值运算符
    {
        return *this;
    }       
    EmptyClass *operator&() { return this; }             // 取址运算符
    const EmptyClass *operator&() const { return this; } // 取址运算符（const 版本）
};