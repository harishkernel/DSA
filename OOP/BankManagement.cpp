#include <bits/stdc++.h>
using namespace std;

class Account {
    string name;
    int accno;
    string atype;
public:
    void getAccountDetails() {
        cout << "\nEnter customer name: ";
        cin >> name;
        cout << "Enter Account no: ";
        cin >> accno;
        cout << "Enter account type: ";
        cin >> atype;
    }
};

int main() {

    return 0;
}