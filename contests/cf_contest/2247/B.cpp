/*
 * File: B.cpp
 * Author: Harish Muthaiyan
 * Created: Saturday, July 18th 2026, 8:29:58 pm
 */

#include <bits/stdc++.h>
using namespace std;
void __dbg() {cerr << '\n';}

template<typename Head, typename... Tail>
void __dbg(Head H, Tail... T) {
    cerr << H;
    if(sizeof...(T)) cerr << ", ";
    __dbg(T...);
}

#define dbg(...) cerr << "DEBUG: [" << #__VA_ARGS__ << "] = ", __dbg(__VA_ARGS__)

void run_case() {
    /**
     * but say k,m = 10, 100
     * doubt there are possibilities,
     * nope
     */
    int n, k, m;
    cin >> n >> k >> m;
    if (k > m) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    int x = m-k+1;
    for (int i = 1; i <= n; i++) {
        if (i%k == 0) { // 3 - 3 matches; all 1's
            cout << x << " ";
        } else {
            cout << 1 << " ";
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    cin >> tt;
    while (tt--) {
       run_case();
    }
    return 0;
}