class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        
        n = len(graph)
        color = [0 for i in range(n)]
        WHITE, GREY, BLACK = 0, -1, 1
        
        def isCyclic(node):
            color[node] = GREY # mark as grey
            
            for neighbour in graph[node]:
                if color[neighbour] is GREY: # neighbour is grey, found a cycle
                    return True
                if color[neighbour] is WHITE: # neighbour is white, check
                    if isCyclic(neighbour):
                        return True
            
            color[node] = BLACK # mark as black
                
        
        for i in range(n):
            if color[i] is WHITE:
                isCyclic(i)
                
        ans = []
        for i in range(n):
            if color[i] is not GREY:
                ans.append(i)
        
        return ans
            