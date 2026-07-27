/*
 * File: 1878C.cpp
 * Author: Harish Muthaiyan
 * Created: Monday, July 27th 2026, 5:50:53 pm
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
	ll n, k, x;
	cin >> n >> k >> x;
	ll largest_k = (n*(n+1)) / 2 - ((n-k)*(n-k+1)) / 2;
    ll smallest_k = (k*(k+1)) / 2;
    if(x >= smallest_k && x <= largest_k) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
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