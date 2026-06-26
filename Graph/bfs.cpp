#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int src, vector<vector<int>>& adj) {
    vector<int> ans;
    int n = adj.size();
    vector<bool> vis(n, false);

    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(int v: adj[node]) {
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return ans;
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

    vector<int> ans = bfs(1, adj);

    cout << "bfs: ";
    for(int x: ans) {
        cout << x << " ";
    }
    cout << '\n';
    return 0;
}