/*
 * File: 1766A.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, July 21st 2026, 6:21:30 pm
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
    /**
     * n = 42, ans = 9
     * n = 33 ans = 10
     * n = 23, ans = 11
     * n = 13, ans = 12
     * n = 3, ans = 13 
     */
    // if(n < 10) {
    //     cout << ans << '\n';
    //     return;
    // }
    // int i = 11;
    // // dbg(n);
    // while(i < n) {
    //     // dbg(i, ans);
    //     ans++;
    //     i += 10;
    // }
    // ans = (n%10 == 0 ? ans : ans-1);
    // // dbg(ans);
    // // cout << '\n';
    string s = to_string(n);
    int d = s.length();
    int first = s[0] - '0';
    int ans = 9*(d-1) + first;
    cout << ans << '\n';
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
