/*
 * File: B.cpp
 * Author: Harish Muthaiyan
 * Created: Saturday, August 1st 2026, 8:23:21 pm
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
	int n, m;
	cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    if(n < 2*m) {
        cout << "NO\n";
        return;
    }
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

    vector<int> left, right;
    for(int i = 0; i < m; i++) left.push_back(a[i]);
    for(int i = n-m; i < n; i++) right.push_back(a[i]);

    // if no such x <= b[i] <= y
    for(int i = 0; i < m; i++) {
        if(!(left[i] < b[i] && b[i] < right[i])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
