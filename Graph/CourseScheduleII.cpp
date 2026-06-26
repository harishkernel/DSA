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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /**
         * Apply Topological sorting and return the sorting if no cycle else {}
         */
        int n = numCourses;
        vector<vector<int>> adj = add_edges(n, prerequisites);
        vector<int> topo;
        vector<int> indeg(n, 0);

        for(int i = 0; i < n; i++) {
            for(int v: adj[i]) {
                indeg[v]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int v: adj[node]) {
                indeg[v]--;
                if(indeg[v] == 0) {
                    q.push(v);
                }
            }
            topo.push_back(node);
        }
        return (topo.size() != n ? vector<int>{} : topo);
    }
};


int main() {
    Solution s;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> ans = s.findOrder(numCourses, prerequisites);

    if(ans.size() == 0) {
        cout << "cycle detected\n";
    } else {
        cout << "cycle not detected\n";
    }

    for(int x: ans) {
        cout << x << " ";
    }
    
    return 0;
}