#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i = 1; i < n; i++) {
            if(a[i-1] > a[i]) {
                ans.push_back(a[i]);
            }
            ans.push_back(a[i]);
        }
        cout << ans.size() << '\n';
        for(int x: ans) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}