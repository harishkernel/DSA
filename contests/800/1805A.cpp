/*
 * File: 1805A.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 19th 2026, 6:05:39 pm
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
    int n;
    cin >> n;
    vector<int> a(n);
    int _xor = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        _xor ^= a[i];
    }
    if(n&1) {
        cout << _xor << '\n';
    } else {
        if(_xor == 0) {
            cout << 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
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
