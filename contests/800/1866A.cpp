#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = INT_MAX;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        ans = min(ans, abs(x));
    }
    cout << ans << '\n';
    return 0;
}