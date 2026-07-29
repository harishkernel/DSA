/*
 * File: A.cpp
 * Author: Harish Muthaiyan
 * Created: Wednesday, July 29th 2026, 8:14:07 pm
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
	int x, y, z;
    cin >> x >> y >> z;
    if (y >= z) {
        cout << -1 << '\n';
    } else {
        // cout << ceil(x / (z - y)) << '\n'; A/B = (A+B-1)/B
		cout << (x + (z - y) - 1) / (z - y) << '\n';
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
