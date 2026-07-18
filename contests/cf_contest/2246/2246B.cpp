/*
 * File: 2246B.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 12th 2026, 8:25:53 pm
 */

#include <bits/stdc++.h>
using ll = long long;
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
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    if (n == 2) {
        cout << -1 << '\n';
        return;
    }
    cout << "1 2 3";
    ll sum = 6;
    for (int i = 4; i <= n; i++) {
        cout << " ";
        cout << sum;
        sum *= 2;
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
