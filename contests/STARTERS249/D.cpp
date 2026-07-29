/*
 * File: d.cpp
 * Author: Harish Muthaiyan
 * Created: Wednesday, July 29th 2026, 10:00:33 pm
 */

#include <bits/stdc++.h>
using ll = long long;
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
	ll n;
	cin >> n;
	vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    /**
     * sus: NSE ? NGE ?
     * montonic stack????
     */

    
    
    auto getPSE = [&]() -> vector<ll> {
        stack<ll> st;
        vector<ll> pse(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        return pse;
    };
    
    auto getNSE = [&]() -> vector<ll> {
        stack<ll> st;
        vector<ll> nse(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        return nse;
    };

    vector<ll> pse = getPSE(), nse = getNSE();
    vector<bool> valley(n, false);
    for (int i = 1; i < n - 1; i++) {
        if(pse[i] < i - 1 && nse[i] > i + 1) {
            valley[i] = true;
        }
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll val = a[i];
        if (i > 0 && i < n - 1 && valley[i - 1] && valley[i + 1]) {
            val = min(a[i - 1], a[i + 1]);
        } else if (i > 0 && valley[i - 1]) {
            val = a[i - 1];
        } else if (i < n - 1 && valley[i + 1]) {
            val = a[i + 1];
        }
        sum += val;
    }
    cout << sum << '\n';
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
