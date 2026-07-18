#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
        int n, mini = INT_MAX; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mini = min(mini, a[i]);
        }
        vector<int> b, c;
        for(int i = 0; i < n; i++) {
            if(a[i] == mini) {
                b.push_back(a[i]);
            } else if(mini % a[i] != 0) {
                c.push_back(a[i]);
            }
        }
        if(c.size() == 0) {
            cout << -1 << '\n';
        } else {
            cout << b.size() << " " << c.size() << '\n';
            for(int x: b) cout << x << " ";
            cout << '\n';
            for(int x: c) cout << x << " ";
            cout << '\n';
        }
    }
    return 0;
}