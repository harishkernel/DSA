#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "\nAdjacency list\n";
    for(int i = 0; i < n+1; i++) {
        cout << i << ": ";
        for(int neigh: adj[i]) {
            cout << neigh << " ";
        }
        cout << '\n';
    }

    return 0;
}