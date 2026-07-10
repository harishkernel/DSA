#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void debug_out() { cerr << '\n'; }

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H;
    if (sizeof...(T)) cerr << ", ";
    debug_out(T...);
}

#define dbg(...) cerr << "DEBUG: [" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__)

void run_case() {
    ll n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(!is_sorted(a.begin(), a.end())) {
            cout << 0 << '\n';
            return;
        }
        int mini_idx = 0;
        ll mini = LLONG_MAX;
        for(int i = 1; i < n; i++) {
            if(mini > a[i] - a[i-1]) {
                mini = a[i] - a[i-1];
                mini_idx = i;
            }
        }
        ll x = a[mini_idx-1], y = a[mini_idx];
        cout << ((y-x)/2)+1 << '\n';
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