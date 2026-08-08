/*
 * File: D.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, August 4th 2026, 9:48:15 pm
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
	int n;
	cin >> n;
	vector<ll> b(n);
    map<ll, ll> mpp;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        mpp[b[i]]++;    //a[i] -> (_, _,....) 
    }

    if(mpp.begin()->first != 0) {
        cout << -1 << '\n';
        return;
    }   // first cand MUST be 0

    map<ll, ll> shadows;
    ll prev = 0;
    
    for(auto it = mpp.begin(); it != mpp.end(); it++) {
        ll curr= it->first;
        ll cnt = it->second;

        auto n = std::next(it);
        if(n != mpp.end()) {
            // found
            ll next_shad = n ->first;
            ll diff = next_shad - curr;

            if(diff % cnt != 0) {
                cout << -1 << '\n';
                return;
            }

            ll ai = diff / cnt;
            if(ai <= prev) {
                cout << -1 << '\n';
                return;
            }
            shadows[curr] = ai;
            prev = ai;
        } else {
            shadows[curr] = prev+1;
        }
    }
    for(int i = 0; i < n; i++) cout << shadows[b[i]] << " ";
    cout << '\n';
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
