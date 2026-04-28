#include <iostream>
using namespace std;

class A {
public:
    void display() {
        cout << "Inside class A\n";
    }
};

class B : virtual public A {
public:
    void show() {
        cout << "Inside class B\n";
    }
};

class C : virtual public A {

};

class D : public B, public C{

};

int main() {
    D d;
    d.display();
    return 0;
}