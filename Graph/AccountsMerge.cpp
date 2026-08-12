/*
 * File: AccountsMerge.cpp
 * Author: Harish Muthaiyan
 * Created: Thursday, July 31th 2026, 9:41:47 am
 */

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
	vector<int> rank, parent;
	DSU(int n) {
		rank.resize(n+1, 0);
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int findParent(int u) {
		if(parent[u] == u) {
			return u;
		}
		return parent[u] = findParent(parent[u]);
	}

	void unionByRank(int u, int v) {
		int pu = findParent(u);
		int pv = findParent(v);

		if(pu == pv) {
			return;
		}

		if(rank[pu] < rank[pv]) {
			parent[pu] = pv;
		} else if(rank[pv] < rank[pu]) {
			parent[pv] = pu;
		} else {
			parent[pu] = pv;
			rank[pv]++;
		}
	}
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // clearly dsu (emails)
        // parent[account[0]] == parent[account[1]]
		// requirements: email sorted order, UID: email, not name
		int n = accounts.size();
		DSU d(n);

		unordered_map<string, int> mpp;
		for(int i = 0; i < n; i++) {
			for(int j = 1; j < (int)accounts[i].size(); j++) {
				string email = accounts[i][j];
				if(mpp.find(email) == mpp.end()) {
					mpp[email] = i;
				} else {
					int par = mpp[email];
					d.unionByRank(par, i);
				}
			}
		}

		unordered_map<int, set<string>> merged;
		for(auto& it: mpp) {
			string email = it.first;
			int idx = it.second;
			int par = d.findParent(idx);
			merged[par].insert(email);
		}

		vector<vector<string>> ans;
		for(auto& it: merged) {
			int idx = it.first;
			
			vector<string> temp;

			temp.push_back(accounts[idx][0]);	// add name
			temp.insert(temp.end(), it.second.begin(), it.second.end());
			
			ans.push_back(temp);
		}
		return ans;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Solution s;
	vector<vector<string>> accounts = {
		{"John","johnsmith@mail.com","john_newyork@mail.com"},
		{"John","johnsmith@mail.com","john00@mail.com"},
		{"Mary","mary@mail.com"},
		{"John","johnnybravo@mail.com"}
	};

	vector<vector<string>> merged = s.accountsMerge(accounts);
	for(auto v: merged) {
		for(string s: v) {
			cout << s << " ";
		}
		cout << '\n';
	}
	return 0;
}
