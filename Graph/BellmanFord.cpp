/*
 * File: BellmanFord.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 12th 2026, 2:29:18 pm
 */

#include <bits/stdc++.h>
using namespace std;

class BellmanFord { 
public:
    vector<int> bellmanFord(int V, int src, vector<vector<int>>& edges) {
        /**
         * Relax (dist[u] + wt < dist[v]) where u,v,w are the edge param
         * those edges sequentially for V-1 times
         * 
         * WHY V-1?
         * worst case scneario: the sequential update happens once per iteration and happens to
         * be like a LinkedList format
         * 
         * can detect -ve cycles, found if
         * even after V-1 relaxations, if still dist[] reduces,
         * then its in a loop => cycle
         */
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for(int i = 0; i < V-1; i++) {
            for(auto& e: edges) {
                int u = e[0], v = e[1], wt = e[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // after V-1 sequential relaxations it's guaranteed
        // that dist[] has attained min possible dist to all nodes

        for(auto &e: edges) {
            int u = e[0], v = e[1], wt = e[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }
        return dist;
    }
};

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3},
        {1, 3, 2}, {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };
    int V = 5, src = 0;

    BellmanFord b;
    vector<int> dist = b.bellmanFord(V, src, edges);

    if(dist.size() == 1 && dist[0] == -1) {
        cout << "Found -ve edge via bellman ford algorithm\n";
    } else {
        cout << "dist[]: ";
        for(int x: dist) {
            cout << x << " ";
        }
        cout << '\n';
    }
    cout << "Time complexity: " << "O(V*E)\n";
    return 0;
}
