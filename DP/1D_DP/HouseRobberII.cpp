/*
 * File: HouseRobberII.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, August 16th 2026, 6:57:06 pm
 */

#include <bits/stdc++.h>
using namespace std;

int f(int start, int end, vector<int>& nums, vector<int>& dp) {
    // if(start < end) return 0;
    // if(dp[start] != -1) return dp[start];

    // int pick = nums[start] + f(start-2, end, nums, dp);
    // int notPick = f(start-1, end, nums, dp);
    // return dp[start] = max(pick, notPick);

    dp[start] = nums[start];
    for(int i = start+1; i <= end; i++) {
        int pick = (i-2 >= start ? dp[i-2] + nums[i] : nums[i]);
        int notPick = dp[i-1];
        dp[i] = max(pick, notPick);         
    }
    return dp[end];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n < 4) return *max_element(nums.begin(), nums.end());

    vector<int> dp(n, -1);
    int ans1 = f(0, n-2, nums, dp);
    dp.assign(n, -1);
    int ans2 = f(1, n-1, nums, dp);
    return max(ans1, ans2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    vector<int> nums = {1, 2, 3, 1};
    cout << rob(nums) << '\n';
	return 0;
}
