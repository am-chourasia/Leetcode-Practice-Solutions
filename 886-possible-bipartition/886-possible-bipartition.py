WHITE = 10

class Solution:
    def buildGraph(self, n, dislikes):
        graph = [[] for _ in range(n + 1)]
        for u, v in dislikes:
            graph[u].append(v)
            graph[v].append(u)
        return graph
    
    
    def isBipartite(self, graph, node, parent, color, paint):
        color[node] = paint
        required = not paint
        for disliked in graph[node]:
            if disliked is not parent:
                if color[disliked] is WHITE:
                    if self.isBipartite(graph, disliked, node, color, required) is False:
                        return False
                elif color[disliked] is not required:
                    return False

        return True
    
    
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        
        graph = self.buildGraph(n, dislikes)
        color = [WHITE for i in range(n + 1)]
        for i in range(1, n):
            if color[i] is WHITE:
                if self.isBipartite(graph, i, -1, color, True) is False:
                    return False
        
        return True
            