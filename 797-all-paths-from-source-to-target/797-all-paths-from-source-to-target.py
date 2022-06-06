class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        path = []
        allPath = []
        n = len(graph)
        
        def dfs(node):
            path.append(node)
            if node == n - 1:
                allPath.append(path[:])    
            for adj in graph[node]:
                dfs(adj)
            path.pop()
        
        dfs(0)
        return allPath