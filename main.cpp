#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;
class Student
{
    public:
    string name;
    int score;
    Student(string _name, int _score):name(_name), score(_score)
    {

    };
    ~Student()
    {

    };
};


int main(int argc, char**  argv)
{
    cout << "Hello World!" << endl;
    vector<int> arr;
    std::shared_ptr<int> fix1(new int);
    // shared_ptr是个类， 所以不能写成std::shared_ptr<int> p = new int(1); 
    std::shared_ptr<Student> li(new Student("LiHua", 96));
    std::shared_ptr<Student> wang = std::make_shared<Student>("Wang", 98);
    std::cout << li->name << " " << li->score << std::endl;
    std::cout << wang->name << " " << wang->score << std::endl;
    return 0;
}