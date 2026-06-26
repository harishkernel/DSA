#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& ans) {
    vis[u] = true;
    ans.push_back(u);

    for(int v: adj[u]) {
        if(!vis[v]) {
            dfs(v, vis, adj, ans);
        }
    }
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

    /**
     * DFS
     */
    
    vector<int> ans;
    vector<bool> vis(n+1, false);
    for(int i = 0; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, ans);
        }
    }

    cout << "dfs: ";
    for(int x: ans) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}