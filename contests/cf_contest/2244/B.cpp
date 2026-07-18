/*
 * File: B.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, July 14th 2026, 8:46:01 pm
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    ll sum = 0;
    ll reqd = 0;
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        sum += x;
        reqd += i;
        if (sum < reqd) {
            flag = false;
        }
    }
    cout << (flag ? "YES" : "NO") << '\n';
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
