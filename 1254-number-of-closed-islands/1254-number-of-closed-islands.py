class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        
        def dfs(i, j):
            if i < 0 or i >= n or j < 0 or j >= m:
                return 0
            if grid[i][j] != 0:
                return False
            
            grid[i][j] = 2
            down = dfs(i + 1, j)
            right = dfs(i, j - 1)
            top = dfs(i - 1, j)
            left = dfs(i, j + 1)
            isEdge = i == 0 or i == n - 1 or j == 0 or j == m - 1
            return left or right or top or down or isEdge
        
        ans = 0
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0 and not dfs(i, j):
                    ans += 1
        
        return ans