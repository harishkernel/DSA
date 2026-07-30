/*
 * File: MostStonesRemoved.cpp
 * Author: Harish Muthaiyan
 * Created: Tuesday, July 28th 2026, 9:24:42 pm
 */

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> size, parent;
    DSU(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int u) {
        if(parent[u] == u) {
            return u;
        }
        // path compression
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        
        if (pu == pv) return;

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
public:
    int removeStones(vector<vector<int>>& stones) {
        /**
         * gather edges from stones (treated as matrix)
         * col = n+i+1 mapping to nodes in DSU
         * then union them
         * remove invalid components (check size == 1??, if so then union by size applies not rank)
         */
        
        int maxRow = 0, maxCol = 0;
        for(auto& stone: stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }
        int n = maxRow + maxCol + 1;
        DSU dsu(n);
        for(auto& it: stones) {
            // add edges
            int nodalRow = it[0];
            int nodalCol = it[1] + maxRow + 1;
            dsu.unionByRank(nodalRow, nodalCol);
        }

        int valid = 0;
        for(int i = 0; i <= n; i++) {
            // valid ones: p[u] = u, size[u] > 1
            if(dsu.findParent(i) == i && dsu.size[i] > 1) {
                valid++;
            }
        }
        return stones.size() - valid;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Solution s;
    vector<vector<int>> stones = {
        {0,0},{0,1},{1,0},{1,2},{2,1},{2,2}
    };

    cout << s.removeStones(stones) << '\n';
    return 0;
}