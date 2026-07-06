#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        string s1, s2;
        cin >> n >> m >> s1 >> s2;
        int op = 0;
        bool found = false;
        for(int i = 1; i <= 6; i++) {
            if(s1.find(s2) != string::npos) {
                found = true;
                break;
            }
            s1.append(s1);
            op++;
        }
        cout << (found ? op : -1) << '\n';
    }
    return 0;
}