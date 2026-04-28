#include <iostream>
using namespace std;

class A {
public:
    int x;
};

class B : private A {
public:
    void getDetails() {
        cout << "\nEnter the value of x: ";
        cin >> x;
    }
    void display() {
        cout << "value of x: " << x;
    }
};

int main() {
    B b;
    b.getDetails();
    b.display();
    return 0;
}