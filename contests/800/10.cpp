#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
        char arr[10][10];
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cin >> arr[i][j];
            }
        }

        int top = 0, left = 0, right = 9, bottom = 9;
        int lvl = 1, ans = 0;
        while(lvl <= 5) {
            int cnt = 0;
            for(int i = left; i <= right; i++) {
                if(arr[top][i] == 'X') {
                    ++cnt;
                }
            }
            top++;
            for(int i = top; i <= bottom; i++) {
                if(arr[i][right] == 'X') {
                    ++cnt;
                }
            }
            right--;
            for(int i = right; i >= left; i--) {
                if(arr[bottom][i] == 'X') {
                    ++cnt;
                }
            }
            bottom--;
            for(int i = bottom; i >= top; i--) {
                if(arr[i][left] == 'X') {
                    ++cnt;
                }
            }
            left++;
            ans += cnt*lvl;
            lvl++;
        }
        cout << ans << '\n';
    }
    return 0;
}