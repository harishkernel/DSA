#include <bits/stdc++.h>
using namespace std;
using pii = pair<pair<int, int>, int>;

class Solution {
private:
    vector<vector<pair<int, int>>> build(int n, const vector<vector<int>>& flights) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        return adj;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /**
         * dijkstra wont work, as minheap(distance) tries for min dist not with wrt k
         * thus use bfs-queue
         */
        
        vector<vector<pair<int, int>>> adj = build(n, flights);
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pii> q;
        q.push({{src, 0}, 0});
        while(!q.empty()) {
            auto pp = q.front();
            q.pop();
            int node = pp.first.first, stops = pp.first.second, weight = pp.second;
            
            if(stops > k) {
                continue;
            }

            for(auto neigh: adj[node]) { 
                if(dist[neigh.first] > weight + neigh.second) {
                    dist[neigh.first] = weight + neigh.second;
                    q.push({{neigh.first, stops+1}, dist[neigh.first]});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<vector<int>> flights = {
        {0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}
    };
    int n = 4, src = 0, dst = 3, k = 1;
    cout << s.findCheapestPrice(n, flights, src, dst, k) << '\n';
    return 0;
}