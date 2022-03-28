#include "main.h"

using namespace std;

A s_a("全局静态变量");
A g_a("全局变量");
// A s_a("全局静态变量");

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    GetA();
    return 0;
}