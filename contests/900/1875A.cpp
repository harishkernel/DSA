/*
 * File: 1875A.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, July 28th 2026, 6:49:43 pm
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
	ll a, b, n;
    cin >> a >> b >> n;
    ll s = b;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s += min(1 + x, a); // c = 1, greedily wait till last moment - 1
        // even at c = 1, then c + x > a, fall back to a
        --s; // timer--;    
    }
    cout << s << '\n';
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
