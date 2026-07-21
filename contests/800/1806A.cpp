/*
 * File: 1806A.cpp
 * Author: Harish Muthaiyan
 * Created: Saturday, July 18th 2026, 6:09:38 pm
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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(y2 - y1 < x2 - x1 || y1 > y2) {
        cout << -1 << '\n';
    } else {
        ll ans = 0;
        ll yDiff = y2 - y1;
        x1 += yDiff;
        y1 += yDiff;
        ans += yDiff;
        ans += (x1 - x2);
        cout << ans << '\n';
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
