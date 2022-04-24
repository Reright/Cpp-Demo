#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <numeric>

using namespace std;

void TestString()
{
    string str("I love Shanghai!");
    string tmp("love");
    cout << "============String Replace============" << endl;
    int it = str.find(tmp);
    if(it!= string::npos) {  //如果找不到，返回string::npos;
        str.replace(it, 4, "like");  // 找到的话， 用"like"替换后面4个字符，
        // 可以用“like”替换超过4个字符， 那么后面3个字符将被删除
    }
    cout << str << endl;
    str.replace(str.begin(), str.begin() + 2, "We ");  // 后一个it不包含
    cout << str << endl;

    cout << "============String Insert============" << endl;
    /*
    string的成员函数insert有以下多种重载：
    string &insert(int p0, const char *s);——在p0位置插入字符串s
    string &insert(int p0, const char *s, int n);——在p0位置插入字符串s的前n个字符
    string &insert(int p0,const string &s);——在p0位置插入字符串s
    string &insert(int p0,const string &s, int pos, int n);——在p0位置插入字符串s从pos开始的连续n个字符
    string &insert(int p0, int n, char c);//在p0处插入n个字符c
    iterator insert(iterator it, char c);//在it处插入字符c，返回插入后迭代器的位置
    void insert(iterator it, const_iterator first, const_iteratorlast);//在it处插入从first开始至last-1的所有字符
    void insert(iterator it, int n, char c);//在it处插入n个字符c
    */
    int a = abs(-1 - 3);
    cout << "a = " << a << endl;
    cout << "============String 迭代器加减============" << endl;
    string str2 = str;
    auto iit = str2.begin() + 3;
    cout << "begin() + 3 = " << *iit << endl;
    sort(str2.begin(), str2.end());
    cout << "begin() + 3 = " << *iit << endl;  // 迭代器指向的位置不变，这跟下标索引不同
    cout << str2 << endl;  // 按照ASCII码排序
    cout << "end() - begin() = " << str2.end() - str2.begin() << endl;
    
    
    cout << "============String 后面追加字符(串)============" << endl;
    // append函数是向string的后面追加字符或字符串。
    // 1).向string的后面加C-string
    string s1 = "hello "; const char *c1 = "out here ";
    s1.append(c1); // 把c类型字符串s连接到当前字符串结尾
    cout << s1 << endl;

    // 2).向string的后面加C-string的一部分
    string s2= "hello "; const char *c2 = "out here";
    s2.append(c2,3); // 把c类型字符串s的前n个字符连接到当前字符串结尾
    cout << s2 << endl;

    // 3).向string的后面加string
    string s3 = "hello "; string s4 = "wide "; string s5 = "world ";
    s3.append(s4); 
    cout << s3 << endl;
    s3 += s5; //把字符串s连接到当前字符串的结尾
    cout << s3 << endl;

    // 4).向string的后面加string的一部分
    string s6 = "hello ", s7 = "wide world";
    s6.append(s7, 5, 5); ////把字符串s2中从5开始的5个字符连接到当前字符串的结尾
    cout << s6 << endl;
    string str11 = "hello ", str12 = "wide world";
    str11.append(str12.begin()+5, str12.end()); //把s2的迭代器begin()+5和end()之间的部分连接到当前字符串的结尾
    cout << str11 << endl;
    
    // 5).向string后面加多个字符
    string s11 = "hello ";
    s11.append(4,'!'); //在当前字符串结尾添加4个字符!
    cout << s11 << endl;
    return;
}
