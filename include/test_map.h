#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <numeric>
#include <map>

using namespace std;
using std::setw;  // 需要头文件<iomanip>

class A {
public:
    A(const int a, const char* name):m_a(a), m_name(name)
    {

    }
    A(const A& a)
    {
        this->m_a = a.m_a;
        this->m_name = a.m_name;
        cout << "Copy Constructor & is called!" << endl;
    }
    A(const A&& a)
    {
        this->m_a = a.m_a;
        this->m_name = a.m_name;
        cout << "Copy Constructor && is called!" << endl;
    }
    A& operator=(const A&& a)
    {
        this->m_a = a.m_a;
        this->m_name = a.m_name;
        cout << "Copy Operator is called!" << endl;
        return *this;
    }
    A():m_a(-1), m_name("Default Name")
    {
        cout << "Default Constructor is called!" << endl;
    }
    virtual ~A()
    {
        cout << "A is Destructed!" << endl;
    }
    const char* GetName()
    {
        return m_name;
    }
    int GetValue()
    {
        return m_a;
    }
private:
    int m_a;
    const char* m_name;
};

void ShowMap(map<int, A>& table)
{
    cout << "table now" << endl;
    for(auto c : table)
        cout << left << setw(6) << "ID:" << c.first << ", Name: " << c.second.GetName() << endl;
}

void ShowMap(map<int, A*>& table)
{
    cout << "table now" << endl;
    for(auto c : table)
        cout << left << setw(6) << "ID:" << c.first << ", Name: " << c.second->GetName() << endl;
}

void TestMap()
{
    cout << "=======================Test Map=======================" << endl;
    map<int, A*> table;
    table.emplace(0, new A(1, "Michale"));
    // ShowMap(table);
    map<int, A> ctable;
    ctable.emplace(1, std::move(A(2, "James")));
    ShowMap(ctable);
    ctable.emplace(2, A{3, "Johnson"});
    ShowMap(ctable);
    decltype(table) stable;
    stable.emplace(3, new A(4, "John"));
    // ShowMap(stable);
    // table.emplace_hint();
    ctable.insert(ctable.begin(), make_pair(4, A(4, "Heaven")));  // map是双向迭代器，不支持begin()+n
    // ctable.insert(ctable.begin(), make_pair(4, A(4, "Heaven")));  // map是双向迭代器，不支持begin()+n
    ShowMap(ctable);
    /*
    ** 用[]方式索引map中的项时，编译器会检查必须提供默认构造函数，
    ** 因为用[]的方式会在找不到时插入一个默认值，调用默认构造函数，
    ** 如果不提供则会报错；而使用find函数找到迭代器，通过判断迭代器
    ** 是否为end()则不需要默认构造函数；
    */
    int i = 7;
    cout << "ctable[" << i << "] = " << ctable[i].GetValue() << " " << ctable[i].GetName() << endl;
    auto it = ctable.find(i);
    if(it != ctable.end())
        cout << "ctable[" << i << "] = " << it->second.GetValue() << " " << it->second.GetName() << endl;
    ctable.insert(ctable.end(), make_pair(5, A(10, "Heaven")));
    ctable.insert(ctable.end(), make_pair(17, A(10, "Deng")));
    ctable.insert(ctable.begin(), make_pair(12, A(10, "Cai")));
    ctable.insert(ctable.end(), make_pair(8, A(10, "He")));
    ctable.insert(ctable.end(), make_pair(8, A(10, "Lin")));  // 当检查到有相同key的元素存在时，不插入
    /* “=”需要调用拷贝赋值操作；
    ** 如果自定义了拷贝构造函数，但没有顺带定义拷贝赋值操作，
    ** 会报错；可见自定义拷贝构造函数掩盖了默认的拷贝赋值操作，
    ** 建议这两个一起定义 
    */
    ctable[13] = A(15, "Yang");  
    ShowMap(ctable);
    int era = 11;
    cout << "erase key " << era << ", amount = " << ctable.erase(era) << endl;
    era = 2;
    cout << "erase key " << era << ", amount = " << ctable.erase(era) << endl;
    era = 13;
    cout << "erase key " << era << ", amount = " << ctable.erase(era) << endl;
    ShowMap(ctable);
    int key = 8;
    cout << "amount of key " << key << " is " << ctable.count(key) << endl;
    ShowMap(ctable);
    it = ctable.lower_bound(7);  // 找第一个key >= 7的
    cout << "lower_bound(7) returns key " << it->first << endl;
    it = ctable.upper_bound(7);  // 找第一个key > 7的
    cout << "upper_bound(7) returns key " << it->first << endl;
    // it = equal_range(7);
    /*
    map<int, A> ctable;
    ctable.emplace(1, std::move(A(2, "James")));
    cout << "***" << endl;
    ctable.emplace(1, A(2, "James"));
    cout << "***" << endl;
    ctable.insert(ctable.end(), make_pair(5, A(10, "Heaven")));
    */
}