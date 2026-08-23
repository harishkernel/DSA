#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if(i < 0 || j < 0 || grid[i][j] == -1) {
        return 0;
    }
    if(i == 0 && j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int up = f(i-1, j, grid, dp);
    int left = f(i, j-1, grid, dp);
    return dp[i][j] = up + left;
}

int uniquePathsII(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    if(grid[0][0] == -1 || grid[n-1][m-1] == -1) return 0;

    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if(grid[i][j] == -1) dp[i][j] = 0;
            else {
                int up = 0, left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n-1][m-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid = {
        {0, 0, 0}, {0, -1, 0}, {0, 0, 0}
    };

    cout << uniquePathsII(grid) << '\n';
    return 0;
}