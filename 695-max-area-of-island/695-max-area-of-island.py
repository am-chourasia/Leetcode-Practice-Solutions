class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        n = len(grid)
        m = len(grid[0])
        
        def dfs(i, j):
            if i < 0 or i >= n or j < 0 or j >= m:
                return 0
            if grid[i][j] != 1:
                return 0
            
            grid[i][j] = 2
            down = dfs(i + 1, j)
            right = dfs(i, j - 1)
            top = dfs(i - 1, j)
            left = dfs(i, j + 1)
            return left + right + top + down + 1
        
        ans = 0
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    ans = max(ans, dfs(i, j))
                    
        return ans