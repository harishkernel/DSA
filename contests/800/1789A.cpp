/*
 * File: 1789A.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 19th 2026, 6:41:48 pm
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
    for(auto &x: a) cin >> x;
    bool flag = true;
    int g = a[0];
    for(int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
        if(g > i+1) {
            flag = false;
            break;
        }
    }
    if(flag) cout << "YES" << '\n';
    else {
        for(int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if(gcd(a[i], a[j]) <= 2) {
                    cout << "YES\n";
                    return;
                }
            }
        }
        cout << "NO\n";
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
