#include <iostream>
using namespace std;

class Box {
    int count = 0;
public:
    Box() = default;
    
    void operator ++(int) {
        this -> count += 1;
    }

    void print() {
        cout << "count: " << count << '\n';
    }
};

int main() {
    Box b;
    b++;
    b.print();
}