/*
 * File: C.cpp
 * Author: Harish Muthaiyan
 * Created: Saturday, August 1st 2026, 9:28:38 pm
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

vector<ll> memo;
vector<int> a, left_occ, right_occ;
int n;

ll solve(int idx) {
	if(idx >= 2*n) return 0;
	if(memo[idx] != -1) return memo[idx];
	// o1:
	ll ans = 1+solve(idx+1);
	// o2:
	if(idx == left_occ[a[idx]]) {
		ll r = right_occ[a[idx]];	// find the exact right[a[i]] for that left
		ll window = r-idx+1;
		ll score = (window*window) + solve(r+1);
		ans = max(ans, score);
	}
	return memo[idx] = ans;
}

void run_case() {
	cin >> n;
	a.assign(2*n, 0);
	left_occ.assign(n+1, -1);
	right_occ.assign(n+1, -1);
	memo.assign(2*n, -1);
	
	// O(1) lookup
	for(int i = 0; i < 2*n; i++) {
		cin >> a[i];
		if(left_occ[a[i]] == -1) {
			left_occ[a[i]] = i;
		} else {
			right_occ[a[i]] = i;
		}
	}
	cout << solve(0) << '\n';
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
