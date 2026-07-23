/*
 * File: 1904A.cpp
 * Author: Harish Muthaiyan
 * Created: Wednesday, July 22nd 2026, 8:16:29 pm
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void __dbg() {cerr << '\n';}

template<typename Head, typename... Tail>
void __dbg(Head H, Tail... T) {
	cerr << H;
	if(sizeof...(T)) cerr << ", ";
	__dbg(T...);
}

#define dbg(...) cerr << "DEBUG: [" << #__VA_ARGS__ << "] = ", __dbg(__VA_ARGS__)

void run_case() {
    ll a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;
	const vector<array<ll, 2>> dirs = {
	    {a, b}, {b, a}, {-a, b}, {-a, -b},
	    {-b, a}, {-b, -a}, {a, -b}, {b, -a}
    };

    set<array<ll, 2>> uniques;

    // modify xk, yk
    for(auto [dx1, dy1]: dirs) {
        int nr1 = xk + dx1;
        int nc1 = yk + dy1;
        for(auto [dx2, dy2]: dirs) {
            int nr2 = nr1 + dx2;
            int nc2 = nc1 + dy2;
            if(nr2 == xq && nc2 == yq) {
                uniques.insert({nr1, nc1});
            }
        }
    }
    cout << uniques.size() << '\n';
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
