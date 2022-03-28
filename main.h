#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

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