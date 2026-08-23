/*
 * File: ninja.cpp
 * Author: Harish Muthaiyan
 * Created: Monday, August 17th 2026, 6:27:23 am
 */

#include <bits/stdc++.h>
using namespace std;

int maxPoints(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(day == 0) {
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if(i != last) {
                maxi = max(maxi, arr[day][i]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    for(int i = 0; i < 3; i++) {
        if(i != last) {
            int points = arr[day][i] + maxPoints(day-1, i, arr, dp);
            maxi = max(maxi, points);
        }
    }
    return dp[day][last] = maxi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> arr = {
        {2, 1, 3}, {3, 4, 6}, {10, 1, 6},
        {8, 3, 7}
    };

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // cout << maxPoints(n-1, 3, arr, dp) << '\n';

    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 3; k++) {
                if(k != j) {
                    dp[i][j] = max(dp[i][j], arr[i][k] + dp[i-1][k]);
                }
            }
        }
    }
    cout << dp[n-1][3] << '\n';

    // N x 4 solely for storing the result in dp[n-1][3]

	return 0;
}