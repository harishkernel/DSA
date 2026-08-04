#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> rank, parent;
    DSU(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findParent(int u) {
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    
    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pu == pv) return;
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Solution {
  private:
    vector<int> check(int r, int c, int n, int m) {
        const int dirs[4][2] = {
            {-1, 0}, {0, -1}, {1, 0}, {0, 1}
        };
        
        // return me all neighbours
        vector<int> neigh;
        
        for(auto dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            
            if((nr >= 0 && nr < n) && (nc >= 0 && nc < m)) {
                int node = nr * m + nc;
                if(islands[node]) {
                    neigh.push_back(node);
                }
            }
        }
        return neigh;
    }
  public:
    vector<bool> islands;
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        /*
           online queries => DSU since no. of. connected components, change dynamically
           
           (row, col) mapping => row * m + col
        */
        int maxNode = n*m;
        DSU d(maxNode);
        
        int currComp = 0;
        islands.assign(maxNode, false);
        vector<int> ans;
        
        for(auto& op: operators) {
            int r = op[0], c = op[1];
            int node = r*m + c;
            if(islands[node]) {
                // already made island
            } else {
                islands[node] = true;
                currComp++; // assume as new isolated island
                vector<int> adjNodes = check(r, c, n, m);
                
                for(int adjNode: adjNodes) {
                    if(adjNode != -1) {
                        // union them
                        int pu = d.findParent(node);
                        int pv = d.findParent(adjNode);
                        if(pu != pv) {
                            d.unionByRank(pu, pv);
                            currComp--;   
                        }
                    }
                }
            }
            ans.push_back(currComp);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    int n = 4, m = 5;
    vector<vector<int>> operators = {{1,1},{0,1},{3,3},{3,4}};

    vector<int> ans = s.numOfIslands(n, m, operators);
    cout << "Number of islands, dynamic querying:\n";
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << ", "[i == (int)ans.size()-1];
    }
    cout << '\n';
    return 0;
}