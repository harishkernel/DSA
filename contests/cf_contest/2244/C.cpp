/*
 * File: C.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, July 14th 2026, 8:52:31 pm
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
    // comparing a[0] and other numbers, a[0] < (a[3], a[4], a[5]),
    // not comparing a[1] as diff is not in x or y
    // i.e., for-every i, a[i] > a[x+i] || a[i] > a[y+i] impossible ????
    // gcd trapping lanes ;)
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    int g = gcd(x, y);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        int dist = abs(a[i] - (i+1));
        if(dist % g != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
