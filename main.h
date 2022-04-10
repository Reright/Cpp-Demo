#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <type_traits>

using namespace std;

template<typename T>
remove_reference_t<T>&& dmove(T&& t) {
    return static_cast<remove_reference_t<T>&&>(t);
}

// 先不要管这段鬼代码，只看返回值的类型，remove_reference_t<T>&&。
// 顺便再看一下该函数的名字，move。
// 相信你已经知道，std::move(t) 的作用，是把 t 转换为右值，无论 t 原本是左值还是右值。
// 那这是如何实现的呢？
// 回答是，无论 t 是左值还是右值，
// 都先把 t 对应的类型 T 上的引用给“去掉”，
// 这就是 remove_reference_t<T> 的作用。
// 然后，再把右值给强行绑上，
// 这就是 remove_reference_t<T>&& 中右值符号的作用。
// 最后，再把 t 强行转化为该类型，
// 这就是 return 语句中 static_cast 的作用。

// 顺便提一句，标准库中的 std::move 函数，大体上就是这样实现的。
// 是的，这个神奇的函数，源码只有两三行。
/* 总结：std::move做了三步
   1. 将T类型去掉引用；
   2. 给T强行绑上右值属性，成为右值引用；
   3. 把t强行转化成该类型的右值引用
   这样返回的就是T类型的右值引用
*/

template <typename T>
bool compare(T t1, T t2)
{
    cout << "通用版本：";
    return t1 == t2;
}

// template <> //函数模板特化
bool compare(char *t1, char *t2)
{
    cout << "特化版本：";
    return strcmp(t1, t2) == 0;
}

template<typename T>
    void MatchValue(T t){
        cout << "Match Normal Value\n"; 
    }

template<typename T>
    void MatchValue(T& t){
        cout << "Match Left Value\n"; 
    }

template<typename T>
    void MatchValue(T&& t){
        cout << "Match Right Value\n"; 
    }


//原始的，最通用的版本
template <typename T> struct remove_refrence
{
    typedef T type;  //定义 T 的类型别名为 type
};



//部分版本特例化，将用于左值引用和右值引用
template <class T> struct remove_refrence<T&> //左值引用
{ 
    typedef T type;
};

template <class T> struct remove_refrence<T&&> //右值引用
{ 
    typedef T type;
};

#include<iostream>

using namespace std;

template <typename T>
T add_fun(const T& tmp1, const T& tmp2){  // 万能引用类型，无论左值右值
    return tmp1 + tmp2;
};

template <typename T>
void Swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
};

template <> void Swap<char>(char& a, char& b){  // 显式具体化
    char temp;
    temp = a;
    a = b;
    b = temp;
};

class Base { 
public:
    virtual void dummy() {} 
};
class Derived: public Base { int a; };