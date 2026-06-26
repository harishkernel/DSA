#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<int> dijkstraHeap(int src, int n, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if(wt > dist[node]) continue;   // optimization

        for(auto p: adj[node]) {
            if(wt + p.first < dist[p.second]) {
                dist[p.second] = wt + p.first;
                pq.push({dist[p.second], p.second});
            }
        }
    }
    return dist; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<vector<pii>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].emplace_back(wt, v);
        adj[v].emplace_back(wt, u);
    }

    vector<int> ans = dijkstraHeap(0, n, adj);
    cout << "distance[] = ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ", \n"[i+1 == ans.size()];
    }
    
    return 0;
}