class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [None for i in range(n)]
        
        def checkBipartite(node, parent, paint):
            color[node] = paint
            required = not paint
            
            for neighbour in graph[node]:
                if neighbour is not parent:
                    if color[neighbour] is None:
                        if checkBipartite(neighbour, node, required) is False:
                            return False
                    elif color[neighbour] is not required:
                        return False
            
            return True
        
        for i in range(n):
            if color[i] is None:
                if checkBipartite(i, -1, True) is False:
                    return False
        
        return True