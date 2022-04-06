#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <list>

using namespace std;

using std::setw;  // 需要头文件<iomanip>
inline void ShowList(const list<int>& l)
{
    cout << std::left << std::setw(6) << "Size is" << std::right << std::setw(4) << l.size();
    cout << ":  ";
    std::for_each(l.cbegin(), l.cend(), [](auto c){ cout << c << " ";});
    cout << endl;
}

bool GreaterThan4(const int& a)
{
    return (a > 4);
}

void TestList()
{
    cout << "=======================Test List=======================" << endl;
    vector<int> v(5);
    for(int i = 0; i < 5; i++)
        v[i] = i;
    list<int> l(v.begin(), v.end());
    ShowList(l);
    l.push_back(2);
    ShowList(l);
    l.push_front(8);
    ShowList(l);
    l.pop_back();
    ShowList(l);
    l.pop_front();
    ShowList(l);
    l.assign(8, 0);
    ShowList(l);
    l.assign(v.begin(), v.end());
    ShowList(l);
    l.emplace_back(3);
    ShowList(l);
    l.emplace_front(6);
    ShowList(l);
    cout << "max_size of l is " << hex << "0x" << l.max_size() << dec << endl;
    l.remove(3);  // 删除所有值为3的元素
    ShowList(l);
    l.remove_if(GreaterThan4);  // 入参是一个返回bool值的函数
    ShowList(l);
    l.insert(++l.begin(), 3, 6);  // list支持双向迭代器，不能写成l.begin()+1，只能写it++或++it
    ShowList(l);
    l.push_back(6);
    ShowList(l);
    l.unique();  // 删除连续的相同元素组中除第一个元素以外的其他元素
    ShowList(l);
    l.sort();  // 默认按升序排列
    ShowList(l);
    l.reverse();  // 元素反排
    ShowList(l);
    list<int> li(5);
    li.assign(v.begin(), v.end());
    ShowList(li);
    cout << "l.splice(l.begin(), li, ++li.begin(), ++li.end())" << endl;
    l.splice(l.begin(), li, ++li.begin(), --li.end());
    ShowList(l);
    ShowList(li);
    cout << "l.merge(li)" << endl;
    l.merge(li);
    ShowList(l);
    ShowList(li);
    l.sort();
    ShowList(l);
    l.remove(0);  // 删除所有值为0的元素
    ShowList(l);
    
}