/*
 * File: A.cpp
 * Author: Harish Muthaiyan
 * Created: Saturday, July 18th 2026, 8:02:15 pm
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
    int n, neg = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) neg++;
    }
    if(n&1) {
        cout << "NO\n";
    } else {
        // always decreases / increases by 2 ;-; fr
        // check parity of target count and current count may be
        int target = n/2;
        if(neg % 2 == target % 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
