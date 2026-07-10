#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e12;

class Solution {
    vector<vector<pll>> build(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> adj(n);
        for(auto road: roads) {
            // src, dest, wt
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        return adj;
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        /**
         * dijkstra with MOD at counting
         * dist[pair<int>]
         */
        int src = 0;
        vector<vector<pll>> adj = build(n, roads);
        vector<pll> dist(n, {INF, 0});
        dist[src] = {0, 1}; 

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, src});

        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            ll wt = p.first, node = p.second;

            if(dist[node].first < wt) continue;

            for(auto neigh: adj[node]) {
                ll adjNode = neigh.first, edgeWt = neigh.second;
                if(wt + edgeWt < dist[adjNode].first) {
                    dist[adjNode].first = wt + edgeWt;
                    dist[adjNode].second = dist[node].second;
                    pq.push({dist[adjNode].first, adjNode});
                } else if(wt + edgeWt == dist[adjNode].first) {
                    dist[adjNode].second =  (dist[adjNode].second + dist[node].second) % MOD;
                }
            }
        }
        return dist[n-1].second % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    int n = 7;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    cout << s.countPaths(n, roads) << '\n';
    return 0;
}