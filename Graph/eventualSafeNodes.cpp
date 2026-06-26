#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        /**
         * the problems asks to return all safe nodes (i.e., outdeg[node] = 0, for a safe node)
         * since wkt, Kahn's alg deals with indeg, we can reverse the graph
         * and apply topo sort which is what the prblm wants us to do
         */
        vector<int> safe;
        int n = graph.size();

        
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int v: graph[i]) {
                adj[v].push_back(i);
            }
        }

        // apply topo bfs
        vector<int> indeg(n, 0);
        for(int i = 0; i < n; i++) {
            for(int v: adj[i]) {
                indeg[v]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0)   
                q.push(i);
        }

        while(!q.empty()) {
            int node = q.front(); q.pop();
            safe.push_back(node);

            for(int i: adj[node]) {
                indeg[i]--;
                if(indeg[i] == 0) {
                    q.push(i);
                }
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};

int main() {
    Solution s;

    vector<vector<int>> graph = {
        {1,2},{2,3},{5},{0},{5},{},{}
    };
    vector<int> ans = s.eventualSafeNodes(graph);
    cout << "Safe nodes: ";
    for(int x: ans) {
        cout << x << " ";
    }
    return 0;
}