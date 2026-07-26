/*
 * File: PrimsMST.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 26th 2026, 6:42:40 am
 */

#include <bits/stdc++.h>
using namespace std;

pair<int, vector<pair<int, int>>> primsMST(int V, vector<vector<pair<int, int>>>& adj) {
    vector<pair<int, int>> MST;
    vector<bool> vis(V, false);
    int sum = 0;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    // {wt, node, parent}
    pq.push({0, 0, -1});

    while(!pq.empty()) {
        auto [wt, node, parent] = pq.top();
        pq.pop();

        if(vis[node] == true) continue;
        else {
            vis[node] = true;
            if(parent != -1) 
                MST.emplace_back(parent, node);
            sum += wt;
            for(auto neigh: adj[node]) {
                if(!vis[neigh.second]) {
                    pq.push({neigh.first, neigh.second, node});
                }
            }
        }
    }
    return {sum, MST};
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    
    pair<int, vector<pair<int, int>>> p = primsMST(n, adj);
    int sum = p.first;
    vector<pair<int, int>> mst = p.second;
    cout << "Edges in MST:\n";
    for(auto it: mst) {
        cout << it.first << " - " << it.second << '\n';
    }
    cout << '\n' << "Total sum: " << sum << '\n';
	return 0;
}