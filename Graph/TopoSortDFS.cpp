#include <bits/stdc++.h>
using namespace std;

void dfs(int u, stack<int>& st, vector<bool>& vis, const vector<vector<int>>& adj) {
    vis[u] = true;

    for(int v: adj[u]) {
        if(!vis[v]) {
            dfs(v, st, vis, adj);
        }
    }
    st.push(u);
}

vector<int> topoSortDfs(const vector<vector<int>>& adj) {
    /**
     * Topological sorting using DFS
     * topo-sort: gives linear ordering in DAG
     * ex: if u -> v, ensures 'u' then 'v' in resultant order
     */

    vector<int> topo;
    stack<int> st;

    int n = adj.size();
    vector<bool> vis(n);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }

    while(!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
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
        // DAG
    }

    vector<int> toposort = topoSortDfs(adj);

    cout << "Topological sorting: ";
    for(int x: toposort) {
        cout << x << " ";
    }

    return 0;
}