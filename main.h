#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Person{
protected:
    int m_age;
    const char* m_name;
    const char* m_birthday;
public:
    Person(int age, const char* name, const char* birthday):
        m_age(age), m_name(name), m_birthday(birthday)
    {
        cout << "This Person is " << m_age << " years old, name is "
             << m_name << ", birthday is " << m_birthday << endl;
    }
};

class Student : public Person {
private:
    int stu_id;
    int* stu_score;
public:
    Student(int age, const char* name, const char* birthday, int stuid, int score):
        Person(age, name, birthday), stu_id(stuid)
    {
        cout << name << "'s ID is " << stu_id << endl;
        stu_score = new int(score);
        // cout << "Score is " << stu_score[0] << " " << stu_score[1] << " " << stu_score[2] << endl;
    }

    int GetAge()
    {\
        return m_age;
    }

    const char* GetName()
    {
        return m_name;
    }
};