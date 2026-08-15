/*
 * File: ClimbStairs.cpp
 * Author: Harish Muthaiyan
 * Created: Saturday, August 15th 2026, 9:57:52 am
 */

#include <bits/stdc++.h>
using namespace std;
void __dbg() {cerr << '\n';}

// int distinctWays(int idx, int n) {
//     if (idx == n) {
//         return 1;
//     }
//     if (idx > n) {
//         return 0;
//     }
//     return distinctWays(idx + 1, n) + distinctWays(idx + 2, n);
// }

/* Top Down / Memoization */
// int distinctWays(int idx, int n, vector<int>& dp) {
//     if(idx == n) return 1;
//     if(idx > n) return 0;
//     if(dp[idx] != -1) {
//         return dp[idx];
//     }
//     return dp[idx] = distinctWays(idx+1, n, dp) + distinctWays(idx+2, n, dp);
// }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 3;
    
    vector<int> dp(n+1, -1);
    /* Bottom up / Tabulation */
    
    dp[0] = 1; dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << '\n';

    
	return 0;
}
