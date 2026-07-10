#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(c%2 == 0) {
            // even => A turn
            if(a > b) {
                cout << "First" << '\n';
            } else {
                cout << "Second" << '\n';
            }
        } else {
            // odd => B turn
            if(b > a) {
                cout << "Second" << '\n';
            } else {
                cout << "First" << '\n';
            }
        }
    }
    return 0;
}