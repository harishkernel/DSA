#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int clr, vector<int>& color, vector<vector<int>>& graph) {
    color[u] = clr;

    for(int v: graph[u]) {
        if(color[v] == -1) {
            if(!dfs(v, 1-clr, color, graph)) {
                return false;
            }
        } else if(color[v] == clr) {    // same color = false
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    /**
     * Bipartite:
     * A graph is bipartite when it can be colored with any 2 colors
     * such that adj nodes dont have same color(0 - black, 1 - white)
     * Property:
     * should not have odd length cycle
     * 
     * DFS
     */

    int n = graph.size();
    vector<int> color(n, -1);

    for(int i = 1; i < n; i++) {
        if(color[i] == - 1) {
            if (!dfs(i, 0, color, graph)) {  // 0 - black colored
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (isBipartite(adj) ? "yes" : "no") << '\n';

    return 0;
}