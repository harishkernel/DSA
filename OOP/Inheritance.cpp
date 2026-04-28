#include <iostream>
using namespace std;

class Father {
public:
    void property() {cout << "Father's property\n";}
};

class Mother {
public:
    void cook() {cout << "Mother cooking...\n";}
};

class Son : public Father, public Mother {
public:
    void draw() {cout << "Son's drawing\n";}
};

int main() {
    Son s;
    s.property();
    s.cook();
    s.draw();
}