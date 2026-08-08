/*
 * File: C2.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, August 4th 2026, 8:46:07 pm
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
    string s1, s2;
	int n;
	cin >> n >> s1 >> s2;
    int odd = 0, even = 0;
	for(int i = 0; i < n; i++) {
        if(s1[i] == '1') {
            if(i&1) odd++;
            else even++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(s2[i] == '1') {
            if(i&1) odd--;
            else even--;
        }
    }
    if(odd != 0 || even != 0) {
        cout << -1 << '\n';
        return;
    }
    
    // C2, auto sorted no need to sort manually ig??
    vector<int> odd_there, even_there;
    vector<int> odd_reqd, even_reqd;
    for(int i = 0; i < n; i++) {
        if(s1[i] == '1') {
            if(i&1) odd_there.push_back(i);
            else even_there.push_back(i);
        }
        if(s2[i] == '1') {
            if(i&1) odd_reqd.push_back(i);
            else even_reqd.push_back(i);
        }
    }

    ll ans = 0;
    for(int i = 0; i < (int)even_there.size(); i++) {
        ans += abs(even_there[i] - even_reqd[i])/2;
    }
    for(int i = 0; i < (int)odd_there.size(); i++) {
        ans += abs(odd_there[i] - odd_reqd[i])/2;
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
