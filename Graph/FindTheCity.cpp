/*
 * File: FindTheCity.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, July 12th 2026, 6:41:48 pm
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> build(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjMatrix(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i++) {
            adjMatrix[i][i] = 0;
        }
        for(auto &e: edges) {
            int u = e[0], v = e[1], wt = e[2];
            adjMatrix[u][v] = wt;
            adjMatrix[v][u] = wt;   // UDG
        }
        return adjMatrix;
    }
    void floydWarshall(int n, vector<vector<int>>& adjMatrix) {
        for(int k = 0; k < n; k++) { 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(adjMatrix[i][k] != INT_MAX && adjMatrix[k][j] != INT_MAX) {
                        adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                    }
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        /**
         * Floyd Warshall, then compute max(of all dist[i][j] <= distanceThreshold)
         */
        vector<vector<int>> adjMatrix = build(n, edges);
        floydWarshall(n, adjMatrix);

        int ans = -1, minCnt = INT_MAX;
        for(int i = 0; i < n; i++) {
            int currCnt = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && adjMatrix[i][j] <= distanceThreshold)
                    currCnt++;
            }
            if(currCnt <= minCnt) {
                minCnt = currCnt;
                ans = i;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 4, distanceThreshold = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};

    Solution s;
    cout << s.findTheCity(n, edges, distanceThreshold) << '\n';

    return 0;
}
