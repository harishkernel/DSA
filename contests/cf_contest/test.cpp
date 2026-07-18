/*
 * File: test.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 12th 2026, 8:30:15 pm
 */

#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 50;
    int i = 10;
    int sum = 0;
    while(n--) {
        cout << i << " ";
        i += 10;
        sum += i;
    }
    cout << '\n' << "Sum: " << sum << '\n';

    return 0;
}
