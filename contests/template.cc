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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	while(tt--) {
		run_case();
	}
	return 0;
}