/*
 * File: DSU.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 26th 2026, 2:25:53 pm
 */

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank, parent;
public:
    DSU(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int u) {
        if(u == parent[u]) {
            return u;
        }
        // path compression
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v) {
        /**
         * find ultimate parents of u, v
         * find rank of parents of u, v
         * always connect smaller rank to larger rank
         */
        int pu = findParent(u);
        int pv = findParent(v);
        
        // because if they are anchored to a parent, why would rank++ ???
        if(pu == pv) return;

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
    DSU ds(n);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    
    if(ds.findParent(3) ==  ds.findParent(7)) {
        cout << "Same parent\n";
    } else {
        cout << "Different parent\n";
    }

    ds.unionByRank(3, 7);
    if(ds.findParent(3) ==  ds.findParent(7)) {
        cout << "Same parent\n";
    } else {
        cout << "Different parent\n";
    }

	return 0;
}
