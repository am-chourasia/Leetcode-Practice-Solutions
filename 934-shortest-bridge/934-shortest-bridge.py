class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        
        n = len(grid)
        q1 = deque()
        q2 = deque()
        
        direction = [0, 1, 0, -1, 0]
        
        def isValid(i, j):
            return i < n and i >= 0 and j < n and j >= 0
        
        def addInitials(i, j):
            grid[i][j] = 2
            for d in range(4):
                x, y = i + direction[d], j + direction[d + 1]
                if isValid(x, y):
                    if grid[x][y] is 0:
                        grid[x][y] = 2
                        q2.append((x, y))
                    if grid[x][y] is 1:
                        addInitials(x, y)
        
        for i in range(n):
            for j in range(n):
                if grid[i][j] is 1:
                    addInitials(i, j)
                    break
            else:   
                continue
            break
        
        distance = 0
        while q2:
            distance += 1
            size = len(q2)
            for _ in range(size):
                i, j = q2.popleft()
                for d in range(4):
                    x, y = i + direction[d], j + direction[d + 1]
                    if isValid(x, y):
                        if grid[x][y] is 1:
                            return distance
                        if grid[x][y] is 0:
                            grid[x][y] = 2
                            q2.append((x, y))
        
        return distance