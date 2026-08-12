#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int u, int parent, int tin[], int low[], vector<bool>& vis, vector<bool>& mark, vector<vector<int>>& adj) {
    vis[u] = true;
    tin[u] = low[u] = timer;
    timer++;
    int child = 0;  // for starting node logic
    for(int v: adj[u]) {
        if(v == parent) {
            continue;
        }
        if(!vis[v]) {
            dfs(v, u, tin, low, vis, mark, adj);
            low[u] = min(low[u], low[v]);
            if(low[v] >= tin[u] && parent != -1) {
                mark[u] = true;
            }
            child++;
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
    if(child > 1 && parent == -1) { // parent = -1 => starting node
        mark[u] = true;
    }
}

vector<int> articulationPoints(int n, vector<vector<int>>& adj) {
    /**
     * similar to bridge algorithm, but here we check entire node, so
     * whether child can reach above parent NOT PARENT, low[v] >= tin[node]
     * 
     * separate logic for starting point low[v] >= tin[u] TRUE but might happen that rem.
     * components are still connected
     *
     * low[] = min of all adj nodes except parent and vis[nodes]
     * 
     * IMPORTANT: dont count same articulation point multiple times
     */
    vector<int> ans;
    vector<bool> mark(n, false);  // to avoid overcounting of same articulation point
    int tin[n], low[n];
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++) {
        if(!vis[i])
            dfs(i, -1, tin, low, vis, mark, adj);
    }
    for(int i = 0; i < n; i++) if(mark[i]) ans.push_back(i);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = articulationPoints(n, adj);
    for(int x: ans) {
        cout << x << " ";
    }
    cout << '\n';
    return 0;
}