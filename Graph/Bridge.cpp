/*
 * File: Bridge.cpp
 * Author: Harish Muthaiyan
 * Created: Monday, August 10th 2026, 1:42:39 pm
 */

#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj, vector<vector<int>>& bridges, int time[], int low[]) {
    vis[node] = true;
    time[node] = low[node] = timer;
    timer++;

    for(int u: adj[node]) {
        if(u == parent) continue;   // might be a bridge
        if(!vis[u]) {
            dfs(u, node, vis, adj, bridges, time, low);
            low[node] = min(low[node], low[u]);
            if(low[u] > time[node]) {
                bridges.push_back({u, node});
            }
        } else {
            low[node] = min(low[node], time[u]);
        }
    }
}

vector<vector<int>> countBridges(int n, vector<vector<int>>& adj) {
    /**
     * Tarjan's algorithm to find bridges:
     * 1. DFS, with timeOfInsertion[] and lowestTimeOfInsertion[]
     * 2. while return update time[] and low[]
     */

     /* DFS */
    int time[n], low[n];
    vector<vector<int>> bridges;
    vector<bool> vis(n, false);
    dfs(1, -1, vis, adj, bridges, time, low);
    return bridges;
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

    vector<vector<int>> ans = countBridges(n, adj);
    for(auto& x: ans) {
        for(int y: x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
	return 0;
}
