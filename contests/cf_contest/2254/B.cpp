/*
 * File: B.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, August 4th 2026, 8:20:39 pm
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
    string s;
	int n;
	cin >> n >> s;

    int shrinkL = 1;
    for(int i = 1; i < n; i++) if(s[i] != s[i-1]) shrinkL++;

    int cnt = 0;
	for(int i = 1; i < n-1; i++) {
        if(s[i-1] == s[i+1] && s[i-1] != s[i]) {
            cnt = max(cnt, 2);  // aba
        }
        if(s[i-1] != s[i] && s[i] != s[i+1] && s[i-1] != s[i+1]) {
            cnt = max(cnt, 1); // abc
        }
    }
    cout << shrinkL - cnt << '\n';
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
