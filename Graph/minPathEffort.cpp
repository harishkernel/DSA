#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, pair<int, int>>;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int dirs[4][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            pii p = pq.top();
            int jumpDiff = p.first, r = p.second.first, c = p.second.second;
            pq.pop();

            // if the new diff > exisiting diff, DONT EVEN EXPLORE IT (dist[][])
            if(jumpDiff > dist[r][c]) continue;

            if(r == n-1 && c == m-1) return jumpDiff;

            // dist[][] stores the max. abs(diff)
            for(auto dir: dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if(nr >= 0 && nr < n && nc < m && nc >= 0) {
                    int diff = abs(heights[nr][nc] - heights[r][c]);
                    int newJump = max(diff, jumpDiff);
                    if(dist[nr][nc] > newJump) {
                        dist[nr][nc] = newJump;
                        pq.push({newJump, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<vector<int>> heights = {{1,2,2}, {3,8,2}, {5,3,5}};
    cout << s.minimumEffortPath(heights) << '\n';
    return 0;
}