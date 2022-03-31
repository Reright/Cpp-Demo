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

