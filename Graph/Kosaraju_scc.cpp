/*
 * File: Kosaraju_scc.cpp
 * Author: Harish Muthaiyan
 * Created: Wednesday, August 12th 2026, 6:02:39 pm
 */

#include <bits/stdc++.h>
using namespace std;

class Kosaraju {
private:
    void dfs1(int node, vector<bool>& vis, stack<int>& st, vector<vector<int>>& adj) {
        vis[node] = true;

        for(int v: adj[node]) {
            if(!vis[v]) {
                dfs1(v, vis, st, adj);
            }
        }
        st.push(node);
    }

    void dfs2(int node, vector<bool>& vis, vector<int>& temp, vector<vector<int>>& rev) {
        vis[node] = true;
        temp.push_back(node);
        
        for(auto& it: rev[node]) {
            if(!vis[it]) {
                dfs2(it, vis, temp, rev);
            }
        }
    }
public:
    vector<vector<int>> findSCC(int n, vector<vector<int>>& adj) {
        /**
         * 1. Sort all nodes in finishing time in stack because the last node that gets finished will be a comp of SCC-1
         * 2. Reverse entire graph: as nodes in a SCC can still reach them but not the other ones
         * 3. DFS according to finishing time
         */
        
        // 1. 
         vector<bool> vis(n, false);
        stack<int> st;
        for(int i = 0; i < n; i++)
            if(!vis[i])
                dfs1(i, vis, st, adj);

        // 2.
        vector<vector<int>> rev(n);
        for(int i = 0; i < n; i++)
            for(auto& it: adj[i])
                rev[it].push_back(i);

        // 3.
        vis.assign(n, false);
        vector<vector<int>> ans;
        vector<int> temp;
        while(!st.empty()) {
            int top = st.top(); st.pop();
            
            if(!vis[top]) {
                dfs2(top, vis, temp, rev);
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};


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
    }

    Kosaraju k;
    vector<vector<int>> scc = k.findSCC(n, adj);
    for(auto& it: scc) {
        for(int x: it) {
            cout << x << " ";
        }
        cout << '\n';
    }
	return 0;
}
