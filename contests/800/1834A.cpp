/*
 * File: 1834A.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 12th 2026, 11:33:45 am
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
    int neg = 0, sum = 0, pos = 0, prod = 1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == -1) neg++;
        else pos++;
        sum += x;
        prod *= x;
    }
    int rqd = n/2;
    int ans = 0;

    dbg(neg, pos);
    if(sum < 0) {
        ans = neg - rqd;
        neg = rqd;
    }
    
    if(neg & 1) ans++;
    
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
