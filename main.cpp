#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl;
    vector<int> arr;
    arr.resize(5);
    arr.at(0) = 4;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr.at(i) << endl;
    }
    return 0;
}