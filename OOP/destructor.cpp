#include <bits/stdc++.h>
using namespace std;

class Math {
    int a, b;
public:
    Math() {
        a = 10;
        b = 20;
    }
    ~Math() {
        cout << "destructor called...\n";
    }
    void add() {
        cout << "Total: " << a+b << endl;
    }
};

int main() {
    Math o;
    o.add();
    return 0;
}