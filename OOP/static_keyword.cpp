#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
public:
    static inline int x = 0;
    Student(string name, int age) {
        ++x;
        this -> name = name;
        this -> age = age;
    }
    void print() {
        cout << "Name: " << name << "\nAge: " << age << "\n\n";
    }
};

// int Student::x = 0;
// not mandatory after C++17, as we can use `static inline int x = 0;`

int main() {
    Student s1("ram",22), s2("sam", 16), s3("peter", 19);
    s1.print();
    s2.print();
    s3.print();
    cout << Student::x << " ";
    return 0;
}