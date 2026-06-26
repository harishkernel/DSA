#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> add_edges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const auto& e: edges) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }
        return adj;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            Toposort cant be done returning all N vertices
            thus return false (cycle detected in DG)
        */
        int n = numCourses;
        vector<vector<int>> adj = add_edges(n, prerequisites);

        int indeg[n] = {0};

        for(int u = 0; u < n; u++) {
            for(int v: adj[u]) {
                indeg[v]++;
            }
        }

        
        vector<int> topo;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int v: adj[node]) {
                indeg[v]--;
                if(indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return (topo.size() == n);
    }
};

int main() {
    Solution s;

    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}, {0,1}};
    bool flag = s.canFinish(numCourses, prerequisites);

    // Expected: flag = false
    cout << (!flag ? "yes cycle detected" : "no cycle not detected") << '\n';
    return 0;
}