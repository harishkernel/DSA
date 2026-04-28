#include <iostream>
using namespace std;

/**
 * operators that cant be overloaded are;
 * 1.   :: Scope resolution operator
 * 2.   sizeof()
 * 3.   . Member-selector
 * 4.   * Member-ptr-selector
 * 5.   ?: Ternary operator
 * 
 * CANT BE OVERLOADED
 */

class Complex {
private:
    int real, img;
public:
    Complex() {
        real = 0;
        img = 0;
    }
    Complex(int r, int i) {
        real = r;
        img = i;
    }
    void print() {
        cout << real << "+" << img << "i\n";
    }

    Complex operator + (Complex c) {
        Complex ans;
        ans.real = this -> real + c.real;
        ans.img = this -> img + c.img;
        return ans; 
    }
};

int main() {
    Complex c1(2, 5);
    Complex c2(3, 2);

    Complex c3;
    c3 = c1 + c2;
    c3.print();
    return 0;
}