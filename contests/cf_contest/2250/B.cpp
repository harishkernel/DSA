/*
 * File: B.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 26th 2026, 8:33:11 pm
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
    cin >> n >> k;

    // from sample tc
    if (k == n-1) {
        cout << -1 << '\n';
        return;
    }

    int allowed0 = (n+1)/2;
    int allowed1 = n/2;
    
    int blk = n-k; 
    vector<int> bucket(blk, 1);
    for(int i = 0; i < blk; i++) {
        if (i%2 == 0) allowed0--;
        else allowed1--;
    }
    
    bucket[0] += allowed0;
    if(blk > 1) {
        bucket[1] += allowed1;
    }
    for(int i = 0; i < blk; i++) {
        char c = (i%2 == 0) ? '0' : '1';
        for(int j = 0; j < bucket[i]; j++) {
            cout << c;
        }
    }
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
