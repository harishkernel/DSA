#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<bool>& pathVis, vector<bool>& vis, const vector<vector<int>>& adj) {
    // return true if cycle present at any instance

    pathVis[u] = vis[u] = true;

    for(int v: adj[u]) {
        if(!vis[v]) {
            if(dfs(v, pathVis, vis, adj)) {
                return true;
            }
        } else if(pathVis[v]) {
            return true;
        }
    }
    pathVis[u] = false; // after vis all neigh and going back to left-over disconnected ones
    return false;
}

bool detectCycleDG(vector<vector<int>>& adj) {
    /**
     * Cycle detection in DG
     * normal cyc.det via dfs in UDG will fail
     * because in DG, path visited should also be considered
     * 
     * pathVis[n+1], vis[n+1];
     */
    int n = adj.size();
    vector<bool> pathVis(n+1), vis(n+1);

    for(int i = 1; i < n; i++) {
        if(!vis[i]) {
            if(dfs(i, pathVis, vis, adj)) {
                return true;
            }
        }
    }
    return false;
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
        adj[u].push_back(v); // DG
    }

    cout << (detectCycleDG(adj) ? "Cycle detected " : "Cycle not detected ") << "in DG\n";
    return 0;
}