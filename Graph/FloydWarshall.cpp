/*
 * File: FloydWarshall.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 12th 2026, 6:00:14 pm
 */

#include <bits/stdc++.h>
using namespace std;

class FloydWarshall {
    vector<vector<int>> build(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjMatrix(V, vector<int>(V, INT_MAX));
        for(int i = 0; i < V; i++) {
            adjMatrix[i][i] = 0;
        }
        for(auto &e: edges) {
            int u = e[0], v = e[1], wt = e[2];
            adjMatrix[u][v] = wt; // DG
        }
        return adjMatrix;
    }
public:
    vector<vector<int>> shortestDistance(int V, vector<vector<int>>& edges) {
        vector<vector<int>> dist = build(V, edges); // adjMatrix
        for(int k = 0; k < V; k++) {
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        return dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 5}, {0, 3, 10},
        {1, 2, 3}, {2, 3, 1},
        {3, 0, 2}
    };

    FloydWarshall f;
    vector<vector<int>> dist = f.shortestDistance(V, edges);

    cout << "Multi-source shortest path array:\n";
    for(auto x: dist) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << '\n';
    }
    return 0;
}
