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
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> ans;
	if(x != 1) {
		cout << "YES\n" << n << '\n';
		for(int i = 0; i < n; i++) {
			cout << 1 << ' ';
		}
		cout << '\n';
	} else {
		if(k >= 2 && n % 2 == 0) {
			cout << "YES\n" << n/2 << '\n';
			for(int i = 0; i < n/2; i++) {
				cout << 2 << ' ';
			}
			cout << '\n';
		} else if(k >= 3) {
			int two = (n - 3) / 2;
			cout << "YES\n" << 1 + two << '\n';
			cout << 3 << ' ' << '\n';
			for(int i = 0; i < two; i++) {
				cout << 2 << ' ';
			}
			cout << '\n';
		} else {
			cout << "NO\n";
		}
	}
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