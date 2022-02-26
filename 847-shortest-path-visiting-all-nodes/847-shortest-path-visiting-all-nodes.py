class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        
        n = len(graph)
        if n == 1:
            return 0
        
        allTraversed = (1 << n) - 1
        queue = deque([(i, (1 << i)) for i in range(n)])
        visited_pair = set(queue)
        
        level = 0
        while queue:
            size = len(queue)
            for i in range(size):
                currentNode, traversed = queue.popleft()
                for neighbour in graph[currentNode]:
                    newTraversed = traversed | (1 << neighbour)
                    if newTraversed == allTraversed:
                        return level + 1
                    if (neighbour, newTraversed) not in visited_pair:
                        visited_pair.add((neighbour, newTraversed))
                        queue.append((neighbour, newTraversed))
            level += 1
        
        return level
            