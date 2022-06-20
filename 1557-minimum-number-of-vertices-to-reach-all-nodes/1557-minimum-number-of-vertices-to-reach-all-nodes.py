class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        indegree = [0 for _ in range(n)]
        for u, v in edges:
            indegree[v] += 1
        ans = [i for i in range(n) if indegree[i] == 0]
        return ans