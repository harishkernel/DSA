#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void start() {
        cout << "Starting Vehicle..\n";
    }
};

/*
    by making base class function virtual
    it implements dervied class functions
*/

class Car: public Vehicle {
public:
    void start() {
        cout << "Starting Car..\n";
    }
};

class Bike: public Vehicle {
public:
    void start() {
        cout << "Starting Bike..\n";
    }
};

class Truck: public Vehicle {
public:
    void start() {
        cout << "Starting Truck..\n";
    }
};

int main() {
    Vehicle *v;
    // v = new Car();
    // v = new Bike();
    v = new Truck();

    v -> start();
    return 0;
}