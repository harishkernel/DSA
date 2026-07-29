/*
 * File: C.cpp
 * Author: Harish Muthaiyan
 * Created: Wednesday, July 29th 2026, 8:32:59 pm
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
	ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll mini = 1e18;
    ll maxi = -1;
    for (int i = 0; i < n / 2; i++) {
        if (a[i] == a[n - i - 1]) {
            continue;
        }
        if (abs(a[i] - a[n - i - 1]) != 2) {
            cout << "NO\n";
            return;
        }
        ll l = min(a[i], a[n - i - 1]);
        mini = min(mini, l);
        maxi = max(maxi, l);
    }
    if (maxi == -1 || maxi - mini <= 1) {
        // all equal
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt = 1;
	cin >> tt;
	auto start = chrono::high_resolution_clock::now();
	while (tt--) {
		run_case();
	}
	auto end = chrono::high_resolution_clock::now();
	#ifndef ONLINE_JUDGE
		cerr << "\nTime: "
     	<< chrono::duration<double, milli>(end - start).count()
     	<< " ms\n";
	#endif
	return 0;
}
