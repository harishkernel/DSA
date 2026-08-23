/*
 * File: FrogKJump.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, August 16th 2026, 12:21:33 pm
 */

#include <bits/stdc++.h>
using namespace std;

// int minJumps(int idx, vector<int>& heights, int k, vector<int>& dp) {
//     if(idx == 0) {
//         return 0;
//     }

//     if(dp[idx] != -1) return dp[idx];

//     int mini = INT_MAX;

//     for(int j = 1; j <= k; j++) {
//         if(idx - j >= 0) {
//             int jump = minJumps(idx - j, heights, k, dp) + abs(heights[idx] - heights[idx-j]);
//             mini = min(mini, jump);
//         }
//     }
//     return dp[idx] = mini;
// }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> heights = {10, 30, 40, 50, 20};
    int n = heights.size();
    vector<int> dp(n, -1);
    int k = 3;

    // cout << minJumps(heights.size()-1, heights, k, dp) << '\n';    // 30

    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        int mini = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                mini = min(mini, jump);
            }
        }
        dp[i] = mini;
    }
    cout << dp[n-1] << '\n';
	return 0;
}
