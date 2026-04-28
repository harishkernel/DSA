#include <iostream>
using namespace std;

class Bike {
public:
    virtual void start() = 0;   // pure virtual function
};

class Apache : public Bike{
public:
    void start() {
        cout << "Apache start" << endl;
    }
};

int main() {
    Bike* b = new Apache();
    b -> start();
    return 0;
}