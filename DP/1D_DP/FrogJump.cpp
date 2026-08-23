/*
 * File: FrogJump.cpp
 * Author: Harish Muthaiyan
 * Created: Saturday, August 15th 2026, 12:09:46 pm
 */

#include <bits/stdc++.h>
using namespace std;

// int frogJump(int idx, int n, vector<int>& heights, vector<int>& dp) {
//     if(idx == 0) return 0;
//     if(dp[idx] != -1) return dp[idx];   // solved already

//     int cost1 = frogJump(idx-1, n, heights, dp) + abs(heights[idx] - heights[idx-1]);
//     int cost2 = INT_MAX;
//     if(idx >= 2) {
//         cost2 = frogJump(idx-2, n, heights, dp) + abs(heights[idx] - heights[idx-2]);
//     }
//     return dp[idx] = min(cost1, cost2);
// }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n = 4;
    vector<int> heights = {10, 20, 30, 10};
    vector<int> dp(n, -1);

    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        int cost1 = dp[i-1] + abs(heights[i-1] - heights[i]);
        int cost2 = (i >= 2 ? dp[i-2] + abs(heights[i-2] - heights[i]) : INT_MAX);
        dp[i] = min(cost1, cost2);
    }

    cout << dp[n-1] << '\n'; 
	return 0;
}
