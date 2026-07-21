/*
 * File: 1783A.cpp
 * Author: Harish Muthaiyan
 * Created: Monday, July 20th 2026, 6:36:25 pm
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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(a[0] == a[n-1]) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << a[n-1] << " " << a[0] << " ";
    for(int i = 1; i < n-1; i++) {
        cout << a[i] << " ";
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
