/*
 * File: 1869A.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, July 28th 2026, 8:03:47 pm
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n & 1) {
        cout << 4 << '\n';
        cout << 1 << " " << n-1 << '\n';
        cout << 1 << " " << n-1 << '\n';
        cout << n-1 << " " << n << '\n';
        cout << n-1 << " " << n << '\n';
    } else {
        cout << 2 << '\n';
        cout << 1 << " " << n << '\n';
        cout << 1 << " " << n << '\n';
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
