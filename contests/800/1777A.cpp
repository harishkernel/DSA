/*
 * File: 1777A.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, July 21st 2026, 5:45:02 pm
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
    int ans = 0, k = 1;
    for(int i = 1; i < n; i++) {
        if((a[i]&1) == (a[i-1]&1)) {
            ++k;
        } else {
            ans += k-1;
            k= 1;
        }
    }
    ans += k-1; 
    cout << ans << '\n';
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
