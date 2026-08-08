/*
 * File: A.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, August 4th 2026, 8:08:00 pm
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
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    while(1) {
        if(a == b || b == c || a == c) {
            cout << ans << '\n';
            return;
        }
        if(a > b && a > c) {
            if(b < c) {
                a--;
                b++;
            } else {
                a--;
                c++;
            }
        } else if(b > a && b > c) {
            if(a < c) {
                b--;
                a++;
            } else {
                b--;
                c++;
            }
        } else {
            if(a < b) {
                c--;
                a++;
            } else {
                c--;
                b++;
            }
        }
        ans++;
    }
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
