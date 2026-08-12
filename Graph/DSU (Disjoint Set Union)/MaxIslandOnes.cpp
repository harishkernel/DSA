/*
 * File: MaxIslandOnes.cpp
 * Author: Harish Muthaiyan
 * Created: Saturday, August 8th 2026, 7:56:53 am
 */

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

class DSU {
public:
    vector<int> size, parent;
    DSU (int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int u) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;
        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
    const int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    int maxConnection(vector<vector<int>>& grid) {
        /**
         * Convert (r, c) -> 1D DSU comp, as graph changes dynamicallY
         * (r, c) => r*m+c
         * edge-case: double-counting on same comp, use set
         */
        int n = grid.size(), m = grid[0].size();
        int maxNodes = n*m;
        DSU d(maxNodes);

        /* pre compute conn-comp for DSU using dfs */
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        auto dfs = [&](auto&& self, int r, int c) -> void {
            vis[r][c] = true;
            int node = r*m+c;

            for(auto& dir: dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if(grid[nr][nc] == 1) {
                        int adjNode = nr*m + nc;
                        d.unionBySize(node, adjNode);
                        if(!vis[nr][nc]) self(self, nr, nc);
                    }
                }
            }
        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    dfs(dfs, i, j);
                }
            }
        }

        int ans = *max_element(d.size.begin(), d.size.end());
        
        /* now check by adding ones */
        unordered_set<int> s;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    int sum = 1;
                    for(auto& dir: dirs) {
                        int nr = i + dir[0];
                        int nc = j + dir[1];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                            // do the following only if neigh is also a 1
                            if(grid[nr][nc] == 1) {
                                int par = d.findParent(nr*m + nc);
                                if(!s.contains(par)) {
                                    sum += d.size[par];
                                    s.insert(par);
                                }
                            }
                        }
                    }
                    ans = max(ans, sum);
                    s.clear();
                }
            }
        }
        return ans;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Solution s;
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1}, {1, 1, 0, 1, 1}, {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 0, 1, 1, 1}
    };
    cout << s.maxConnection(grid) << '\n';
	return 0;
}
