#include <iostream>
#include <vector>
#include <memory>
#include <string>

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