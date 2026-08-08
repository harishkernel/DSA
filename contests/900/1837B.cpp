/*
 * File: 1837B.cpp
 * Author: Harish Muthaiyan
 * Created: Monday, August 3rd 2026, 9:18:57 pm
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
    string s;
	cin >> n >> s;
	int len = 1, maxLen = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] ==  s[i]) {
            len++;
        } else {
            len = 1;
        }
        maxLen = max(maxLen, len);
    }
    cout << maxLen + 1 << '\n';
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
