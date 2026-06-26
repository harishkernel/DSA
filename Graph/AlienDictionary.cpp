#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    pair<int, int> getOrdering(string a, string b) {
        int i = 0, j = 0;
        while(i < a.length() && j < b.length()) {
            if(a[i] != b[i]) {
                return {a[i] - 'a', b[i] - 'a'};
            }
            i++;
            j++;
        }
        return {-1, -1};
    }
    vector<int> topoSort(int n, unordered_set<char>& uniques, vector<vector<int>>& adj) {
        queue<int> q;
        vector<int> indeg(n, 0);
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            for(int v: adj[i]) {
                indeg[v]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0 && uniques.count(i+'a')) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            
            for(int v: adj[node]) {
                indeg[v]--;
                if(indeg[v] == 0 && uniques.count(v+'a')) {
                    q.push(v);
                }
            }
        }
        return ans;
    }
  public:
    string findOrder(vector<string> &words) {
        /*
        * consecutive ordering of 2 words denotes the alien order
        * words[] = ["baa", "abcd", "abca", "cab", "cad"],
        * order = b - a - c
        *            /
        *           d
        * topo sort of DG
        */
        
        string ans = "";
        int n = 26;
        vector<vector<int>> adj(n);
        
        for(int i = 1; i < words.size(); i++) {
            string a = words[i-1];
            string b = words[i];
            
            pair<int, int> p = getOrdering(a, b);
            if(p.first == -1 && p.second == -1) {
                if(a.length() > b.length()) {
                    return ans;
                }
                // skip this pair of strings 'a' and 'b'
                continue;
            }
            
            
            adj[p.first].push_back(p.second);
        }
        
        unordered_set<char> uniques;
        for(string word: words) {
            for(char c: word) {
                uniques.insert(c);
            }
        }
        
        vector<int> topo = topoSort(n, uniques, adj);
        if(topo.size() != uniques.size()) {
            // cycle detected
            return "";
        }
        
        for(int x: topo) {
            ans.push_back(x+'a');
        }
        return ans;
    }
};

int main() {
    Solution s;

    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    string ans = s.findOrder(words);

    cout << ans << "\n";
    return 0;
}