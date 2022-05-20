class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        
        n = len(grid)
        m = len(grid[0])
        
        dp = [[0 for j in range(m)] for i in range(n)]
        
        for j in range(m - 1, -1, -1):
            if grid[n - 1][j] is 1:
                break
            dp[n-1][j] = 1
        
        for i in range(n - 1, -1, -1):
            if grid[i][m - 1] is 1:
                break
            dp[i][m-1] = 1
        
        for i in range(n - 2, -1, -1):
            for j in range(m - 2, -1, -1):
                if grid[i][j] is not 1:
                    dp[i][j] = dp[i][j + 1] + dp[i + 1][j]
            
        return dp[0][0]