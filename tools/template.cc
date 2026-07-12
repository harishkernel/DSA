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
	// solve
}

int main() {
	/*
	 * new_problem: ctrl+shift+N		>> use clion-run-config
	 * run_problem: ctrl+shift+B		>> uses cmake
	 */
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		run_case();
	}

	return 0;
}