/*
 * File: fib.cpp
 * Author: Harish Muthaiyan
 * Created: Wednesday, August 12th 2026, 8:03:05 pm
 */

#include <bits/stdc++.h>
using namespace std;


/* Memoization */
// int fib(int n, vector<int>& dp) {
//     if(n <= 1) return n;

//     if(dp[n] != -1) {
//         return dp[n];   // solved already so return
//     }

//     return dp[n] = fib(n-1, dp) + fib(n-2, dp);
// }


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
    cin >> n;
    // vector<int> dp(n+1, -1);

    /* Tabulation */

	// dp[0] = 0, dp[1] = 1;
    // for(int i = 2; i <= n; i++) {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // cout << dp[n] << '\n';  
    
    /* Space Optimization approach */

    int prev2 = 0, prev = 1;
    for(int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << prev << '\n';
    return 0;
}
