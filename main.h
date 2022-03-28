#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class A{
public:
    void funA(){
        cout << "class A" << endl;
    }
};

struct B: A{ // 由于 B 是 struct，A 的默认继承级别为 public
public:
    void funB(){
        cout << "class B" << endl;
    }
};

class C: B{ // 由于 C 是 class，B 的默认继承级别为 private，所以无法访问基类 B 中的 printB 函数
public:
    void funA(){  // 但在明确了public访问权限的情况下，可以重写funA函数
        cout << "class C" << endl;
    }
};


class Base
{
public:
    Base(int a):a_base(a)
    {

    }
private:
    void fun()
    {
        cout << "Base fun()" << endl;
    }
    int a_base;
};

class Derive : private Base
{
public:
    Derive(int a, int b) : Base(a), b_der(b)
    {

    }
    // void fun()
    // {
    //     cout << "fun is defined!" << endl;
    // }

    void funD()
    {
        // fun();  // 此时fun是private权限，无法访问
        cout << "funD is defined!" << endl;
    }
    int a_base;
    int b_der;
public:
    static Derive* const create(int n, int m)
    {
        return new Derive(n, m);
    }
};

class Person
{
public:
    Person(const string& name, int age): m_name(name), m_age(age)
    {

    }

    void ShowInfo()
    {
        cout << "姓名: " << m_name << endl;
        cout << "年龄: " << m_age << endl;
    }

protected:
    string m_name;

private:    
    int m_age;
};

class Teacher : public Person
{
public:
    Teacher(const string& name, int age, const string& title):
    Person(name, age), m_title(title)
    {

    }
    void ShowTeacherInfo()
    {
        ShowInfo();  // 正确，public属性子类可见
        cout << "姓名：" << m_name << endl;  // 正确，protected属性子类可见
        // cout << "年龄" << m_age << endl;  // 错误，private属性子类不可见
        cout << "职称" << m_title << endl; // 正确，本类自己的成员
    }

private:
    string m_title;
};