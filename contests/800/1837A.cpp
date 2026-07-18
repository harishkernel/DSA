/*
 * File: 1837A.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 12th 2026, 10:44:50 am
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

void run_case()
{
    int x, k;
    cin >> x >> k;
    if(x%k == 0) {
        cout << 2 << '\n';
        cout << x-1 << " " << 1 << '\n';
    } else {
        cout << 1 << '\n';
        cout << x << '\n';
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