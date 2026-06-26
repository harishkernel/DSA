#include <bits/stdc++.h>
using namespace std;

vector<int> topoBFS(const vector<vector<int>>& adj) {
    /**
     * Kahn's Algortihm:
     * since topo states u -> v so that u,v,....
     * which implies indeg[u] == 0, so put all nodes with indeg[] = 0 in queue
     * keep updating the indeg[] and queue<>
     */

    vector<int> ans;
    int n = adj.size();
    int indegree[n] = {0};

    for(int i = 0; i < n; i++) {
        for(int node: adj[i]) {
            indegree[node]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front(); q.pop();
        ans.push_back(node);

        // now the nodes connected to popped node in adj[], indeg--;
        for(int x: adj[node]) {
            indegree[x]--;

            if(indegree[x] == 0){
                q.push(x);
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

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);    // DAG
    }

    vector<int> ans = topoBFS(adj);

    for(int x: ans) {
        cout << x << " ";
    }

    return 0;
}
