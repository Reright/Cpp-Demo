#include "main.h"

using namespace std;

// static A s_a("globalstatic");
A g_a("global");
static A s_a("globalstatic");

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;
    GetA();
    return 0;
}