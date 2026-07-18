/*
 * File: 1814A.cpp
 * Author: Harish Muthaiyan
 * Created: Monday, July 13th 2026, 5:32:47 pm
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
    ll n, k;
    cin >> n >> k;
    cout << ((n-k) % 2 == 0  || n % 2 == 0 ? "YES" : "NO") << '\n';
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
