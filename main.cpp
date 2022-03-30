#include "main.h"

using namespace std;

/*
** 拷贝语义--拷贝--拷贝构造函数--拷贝赋值操作(“=”重载):造成无意义的资源申请和释放
** 转移语义--剪切--转移构造函数--转移赋值操作(“=”重载):直接使用临时对象已申请的资源
** 默认构造函数
** 拷贝构造函数
** 移动构造函数
** 拷贝赋值
** 移动赋值
** 赋值构造函数
*/

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    return 0;
}