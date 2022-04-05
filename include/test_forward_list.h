#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <list>
#include <forward_list>

using std::setw;  // 需要头文件<iomanip>
inline void ShowList(const forward_list<int>& l)
{
    // forward_list 没有size()方法
    std::for_each(l.cbegin(), l.cend(), [](auto c){ cout << c << " ";});
    cout << endl;
}

void TestForwardList()
{
    cout << "=======================Test ForwardList=======================" << endl;
    vector<int> v(5);
    for(int i = 0; i < 5; i++)
        v[i] = i;
    forward_list<int> l(v.begin(), v.end());
    ShowList(l);
    // forward_list是单向链表，只能在迭代器的后面插入值, 而vector.insert()是在迭代器前面插入
    l.insert_after(l.before_begin(), -1);  // 相当于push_front()
    ShowList(l);
    l.insert_after(l.begin(), -2);
    ShowList(l);
    l.erase_after(l.begin());
    ShowList(l);
    l.emplace_after(l.begin(), 7);
    ShowList(l);
    // l.emplace_front(l.begin(), 9);
    // ShowList(l);

}