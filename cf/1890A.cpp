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
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mpp[a[i]]++;
        }
        bool flag = false;
        for(auto &it: mpp) {
            if(it.second == n || (mpp.size() == 2 && it.second == n/2)) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}