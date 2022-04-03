#include "main.h"

using namespace std;

int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl << endl << endl;

    Student li(15, "Lizhi", "1989-08-21", 8, 98);
    cout << li.GetName() << endl;
    Student li2 = li;
    return 0;
}