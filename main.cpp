#include "main.h"

using namespace std;


void Test()
{
    map<int, std::string> list;
    // list.insert(std::make_pair<1, "LiHua">); // 为什么不对--make_pair是函数，后面两个参数用小括号包含
    list.insert(std::make_pair(1, "LiHua"));
    list.insert(std::make_pair(4, "LiHua"));
    list.insert(std::make_pair(7, "LiHua"));
    list.insert(std::make_pair(2, "LiHua"));
    list.insert(std::make_pair(8, "LiHua"));
    list.insert(std::make_pair(10, "LiHua"));
    for (auto it = list.cbegin(); it != list.cend(); it++) {
        cout << it->first << "---" << it->second << endl;
    }
}

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    Fifo fifo(16, 2, "issueq");  // fifo深度16，默认时延2cycle
    fifo.write(10, new Inst(Add));  // 在第10cycle写入一个Add指令
    fifo.write(11, new Inst(Sub)); 
    
    
    cout << fifo << endl;

    cout << "At cycle 12: " << fifo.read(12)->GetType() << endl;
    fifo.write(12, new Inst(Load));  
    cout << "At cycle 13: " << fifo.read(13)->GetType() << endl;
    fifo.write(13, new Inst(Store)); 
    cout << "At cycle 14: " << fifo.read(14)->GetType() << endl;
    for(int i = 15; i < 35; i++) {
        fifo.write(i, new Inst(Sub));
    }
    // cout << fifo << endl;
    return 0;
}