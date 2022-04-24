#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;

void TestUnorderedSet()
{
    cout << "=======================Test Unordered Set=======================" << endl;
    unordered_set<int> s({5, 70, 1, 2, 3, 3, 3, 4});  // 自动去重但不排序
    s.insert(4);
    for_each(s.begin(), s.end(), [](auto c){ cout << c << " " ; });
    cout << endl;
    auto c = s.find(70);
    if(c != s.end()) {
        cout << *c << endl;
        s.erase(c);
    }
    auto d = find_if(s.begin(), s.end(), [=](auto c){ return c % 2 == 0; });  // predicate要返回一个bool值
    if(d != s.end())
        cout << *d << endl;
    for_each(s.begin(), s.end(), [](auto c){ cout << c << " " ; });
    
}