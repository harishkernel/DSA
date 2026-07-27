/*
 * File: 1883B.cpp
 * Author: Harish Muthaiyan
 * Created: Thursday, July 23rd 2026, 7:30:37 pm
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
	int n, k;
    string s;
	cin >> n >> k >> s;
    vector<int> freq(26, 0);
	for(char c: s) {
        freq[c-'a']++;
    }
    int odd = 0;
    for(int x: freq) {
        if(x&1) ++odd;
    }
    cout << (odd-1 <= k? "YES" : "NO") << '\n';
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
