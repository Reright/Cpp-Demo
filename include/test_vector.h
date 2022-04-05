#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <numeric>

using namespace std;
using std::setw;  // 需要头文件<iomanip>
inline void ShowVec(const vector<int>& v)
{
    cout << std::left << std::setw(6) << "Size is" << std::right << std::setw(4) << v.size();
    cout << ":  ";
    std::for_each(v.cbegin(), v.cend(), [](auto& c){ cout << c << " ";});
    cout << endl;
}

void TestVector()
{
    cout << "=======================Test Vector=======================" << endl;
    cout << "***序列的要求***" << endl;
    vector<int> vec(5, 6);  // 5个元素全部被初始化为6,不写6就默认初始化为0
    ShowVec(vec);
    for(int i = 0; i < 5; i++) {
        vec[i] = i;
    }
    ShowVec(vec);
    vec.insert(vec.begin(), -1);  // 可以通过这种方式近似代替push_front()
    ShowVec(vec);
    vec.erase(vec.begin());  // 可以通过这种方式近似代替pop_front(),但无法直接返回头号元素的值
    ShowVec(vec);
    vec.insert(vec.begin(), 3, -1);  // 将3个-1插入到begin()的前面
    ShowVec(vec);
    vec.erase(vec.begin(), vec.begin() + 3); // 将[begin(), begin()+3)位置的元素删除，注意begin()+3位置的不包括
    ShowVec(vec);
    vec.insert(vec.end(), vec.begin(), vec.begin() + 2);  // 随机迭代器才支持begin()+2的用法
    ShowVec(vec);
    cout << "Before rbegin: " << endl;
    ShowVec(vec);
    cout << "rbegin: " << endl;
    vec.insert(vec.begin(), vec.rbegin(), vec.rbegin() + 2);  // 为啥是这个结果？
    ShowVec(vec);
    vector<int> vect(vec.begin() + 1, vec.end() - 1);
    ShowVec(vect);
    vec.clear();  // 清空所有元素，size置为0;
    ShowVec(vec);

    cout << "\n***序列的可选要求***" << endl;
    vec.push_back(1); // 可以继续添加元素，不受初始容量的限制。
    ShowVec(vec);
    vec.resize(10);  // 重新扩充数组，用0填充
    ShowVec(vec);
    vec.push_back(2);
    ShowVec(vec);
    for(int i = 0; i < 5; i++) {
        vec.push_back(i);
    }
    ShowVec(vec);
    vec.pop_back();
    // vec.pop_front();
    // vec.push_front();  vector没有在front的操作
    ShowVec(vec);
    cout << "vector front element is " << vec.front() << endl;
    cout << "vector back element is " << vec.back() << endl;
    int tmp = 2;
    cout << "vec[" << tmp << "] = " << vec[tmp] << endl;
    cout << "vec.at(" << tmp << ") = " << vec.at(tmp) << endl;
    tmp = 20;  
    cout << "vec[" << tmp << "] = " << vec[tmp] << endl;  // 越界但不报错
    // cout << "vec.at(" << tmp << ") = " << vec.at(tmp) << endl;  // 越界且及时报错
    vec.resize(5);  // 只要前5个，后面全部舍弃
    ShowVec(vec);
    for(int i = 0; i < 5; i++) {
        vec[i] = i + 2;
    }
    vec.push_back(7);
    vec.push_back(8);
    ShowVec(vec);
    ShowVec(vect);
    vec.swap(vect);  // 交换两个vector的元素,它们的长度可以不一致
    ShowVec(vec);
    ShowVec(vect);
    /*典型STL函数之sort*/
    sort(vec.begin(), vec.end());
    ShowVec(vec);
    /*典型STL函数之random_shuffle*/
    // random_shuffle(vect.begin(), vect.end());  // C++14 deprecated but still works
    // ShowVec(vect);
    /*典型STL函数之for_each*/
    std::for_each(vect.begin(), vect.end(), [&](auto& c){ c -= 1;});
    ShowVec(vect);
    // capacity()代表不重新分配内存的话，v可以保持多少元素
    // 每次添加新元素后超过capacity，就会触发重新分配内存，分配时会预留一定空间，以减少重新分配的次数
    cout << "vect capacity is " << vect.capacity() << " vect size is " << vect.size() << endl;
    vect.shrink_to_fit();  // 缩减capacity至size的大小，使它们达成一致
    cout << "vect capacity is " << vect.capacity() << " vect size is " << vect.size() << endl;
    vect.reserve(10);  // 至少保留10个元素的存储空间
    cout << "vect capacity is " << vect.capacity() << " vect size is " << vect.size() << endl;
    vect[2] = 5;
    ShowVec(vect);
    int acc = accumulate(vect.begin(), vect.end(), 0);
    cout << "Sum of vect is " << acc << endl;
    /*典型STL函数之find*/
    auto f = find(vect.begin(), vect.end(), 5);  // 找到第一个满足条件的元素
    cout << "next element of f is " << *(f+2) << endl;
}
