#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
        int n, s = 0;
        cin >> n;
        --n;
        while(n--) {
            int x; cin >> x;
            s += x;
        }
        cout << -s << '\n';
    }
    return 0;
}