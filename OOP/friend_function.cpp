#include <iostream>
using namespace std;

class A {
    int x, y;
public:
    friend void setData();
};

void setData() {
    A obj;
    obj.x = 10;
    obj.y = 20;
    cout << "X: " << obj.x << ", Y: " << obj.y << endl;
}

int main() {
    setData();
    return 0;
}