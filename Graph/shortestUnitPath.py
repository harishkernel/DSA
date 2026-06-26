from collections import deque

class Solution:
    def add_edges(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return adj
    def shortestPath(self, V, edges, src):
        adj = self.add_edges(V, edges)
        dist = [float('inf')] * V
        q = deque([(src, 0)])
        
        dist[src] = 0
        while q:
            node, wt = q.popleft()
            for v in adj[node]:
                if(wt+1 < dist[v]):
                    dist[v] = 1+wt
                    q.append((v, dist[v]))
        
        for i in range(V):
            if dist[i] == float('inf'):
                dist[i] = -1
        return dist

s = Solution()
V = 9
edges = [[0, 1], [0, 3], [1, 2], [3, 4], [4, 5], [2, 6], [5, 6], [6, 7], [6, 8], [7, 8]]
src = 0
print(s.shortestPath(V, edges, src))