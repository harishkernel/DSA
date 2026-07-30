/*
 * File: 1855B.cpp
 * Author: Harish Muthaiyan
 * Created: Thursday, July 30th 2026, 6:51:34 pm
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
    /**
     * [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] ~ [l, l+1, l+2, ....., r] => [1, x] also exists
     * must divide [elements so far] by i, else break, because mod cycle broke already
     * O(log2(1e18)) ~ 50 - 60 works
     */

	ll n;
    cin >> n;

    int i = 1;
    while (n % i == 0) {
        i++;
    }
    cout << i-1 << '\n';
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
