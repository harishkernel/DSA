/*
 * File: DSU.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 26th 2026, 4:03:53 pm
 */

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> size, parent;
public:
    DSU(int n) {
        size.resize(n+1, 1);
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

    void unionBySize(int u, int v) {
        /**
         * find ultimate parents of u, v
         * find rank of parents of u, v
         * always connect smaller rank to larger rank
         */
        int pu = findParent(u);
        int pv = findParent(v);
        
        if (pu == pv) return;   // prevent double counting

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
    DSU ds(n);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    
    if(ds.findParent(3) ==  ds.findParent(7)) {
        cout << "Same parent\n";
    } else {
        cout << "Different parent\n";
    }

    ds.unionBySize(3, 7);
    if(ds.findParent(3) ==  ds.findParent(7)) {
        cout << "Same parent\n";
    } else {
        cout << "Different parent\n";
    }

	return 0;
}
